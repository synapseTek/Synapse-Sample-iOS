//
//  GSBeaconManager.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 08/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//



#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "SNBeaconRadar.h"
#import "SNBeaconConfiguration.h"
#import "SNSurveyAnswer.h"
#import "SNSurveyPlusAnswer.h"
#import "SNRegionMessage.h"
#import "SNBeaconDynamicRadar.h"

@class SNBeaconData;
@class SNBeaconEvent;
@class SNBeaconManager;

/** Once your app creates a Beacon Manager instance it must set a delegate in order to communicate with the framework and receive beacon events.
 */
@protocol SNBeaconManagerDelegate <NSObject>

/** This method is called every time the framework finds a beacon matching one of the rules in your configuration
 @param event the event associated to the detected beacon
 */
- (void)notifyBeaconEvent:(SNBeaconEvent*)event;
/** This method is called every time an error related to beacon ranging occurs, you can use this to either log or present the error to the user
 @param error the error that has occurred, most likely a CoreLocation related NSError
 */
- (void)notifyBeaconError:(NSError*)error;
/** This method is called when a user comes in range of **any** of your beacons
 @param region the beacon region that generated the event, contains major and minor numbers for the detected beacon
 */
- (void)notifyEnterRegion:(CLBeaconRegion*)region;
/** This method is called when a is no longer in range of **any** of your beacons
 @param region the beacon region that generated the event, contains major and minor numbers for the detected beacon
 */
- (void)notifyExitRegion:(CLBeaconRegion*)region;

@optional
/** This method is called when the framework determines a region message is available for display; this is analogue to the enter and exit region events, except it provides a message for your app to display
 @param message the message associated to this event
 */
- (void)didReceiveRegionMessage:(SNRegionMessage *)message;
/** This method is called when the device's Bluetooth antenna is once again available, you can use this to let the app know it's now able to provide location-based functionality
 */
- (void)bluetoothDidBecomeAvailable;
/** This method is called when the device's Bluetooth antenna is no longer available (i.e. it's been turned off), you can use this to warn your users that they should enable it in order to benefit from location-based functionality
 */
- (void)bluetoothDidBecomeUnavailable;

@end

@protocol SNBeaconEvaluationDataDelegate

- (void)managerBeginToEvaluateRules:(SNBeaconManager*)manager;
- (NSDictionary*)manager:(SNBeaconManager*)manaegr dataForEvaluationKey:(NSString*)evaluationKey;

@end

/** The SNBeaconManager class allows your app to properly communicate with the Synapse Framework, in order to use any of the features your app *must* initialize and mantain its own BeaconManager instance.
 */
@interface SNBeaconManager : NSObject<SNBeaconRadarDelegate, CBCentralManagerDelegate> {
    SNBeaconRadar *radar;
    NSString *clientToken;
}

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSArray *configurations;
/** The configuration of your client account.
 It holds all the beacons you have configured, the majors associated to you and all the rules and contents you have created. It is used to evaluate rules every time a beacon event is triggered and to provide your app with the matching content
 Your app should never manipulate the configuration directly, it should instead rely on updateConfiguration: to fetch it from your account.
 */
@property (nonatomic, strong) SNBeaconConfiguration *configuration;
@property (nonatomic, strong) CBCentralManager *bluetoothManager;
/** The manager delegate is required in order to let the app properly comunicate with the framework. The delegate must conform to the SNBeaconManagerDelegate protocol
 */
@property (nonatomic, weak) id<SNBeaconManagerDelegate> managerDelegate;
@property (nonatomic, strong) NSArray *rules;
@property (nonatomic, strong) NSMutableArray *events;
@property (nonatomic, strong) NSObject<SNBeaconEvaluationDataDelegate> *evaluator;
@property (nonatomic, strong) NSString *accessToken;
/** The sandbox token for the sandbox user you wish to use, using an valid sandbox token will enter sandbox mode, which allows you to test the framework without having the resulting events counting towards your monthl API call limit.
 For more information about Sandbox Mode please see XXX (TODO: Link alla KB) */
@property (nonatomic, strong) NSString *sandboxToken;
@property (nonatomic, strong) NSString *deviceID;
@property (nonatomic, strong) NSMutableSet *answeredSurveys;
@property (nonatomic) BOOL leaveTimerRunning;
@property (nonatomic, strong) NSTimer *leaveTimer;
@property (nonatomic, strong) NSString *proximityUUID;

- (id)initWithRules:(NSArray*)rules;
/** Fetches your configuration from the server and applies it to the Beacon Manager. It is mandatory for the beacon ranging features to function and it should be invoked regularly to make sure it's up to date
 @param completion a block object that acts as the completion handler for the update operation, it has no return value and takes a single BOOL argument indicating wether the configuration was updated or not.
 */
- (void)updateConfiguration: (void (^)(BOOL success))completion;
- (void)removeAllEvents;

- (void)clearSurveyAnswers;
/** Checks wether a specific survey was answered or not. Please note that this value is *not* retained after your application is removed from memory. If you wish to have a persistent record you should keep track of the filled surveys manually
 @param surveyID the ID of the survey you wish to check */
- (BOOL)isSurveyAnswered:(NSString *)surveyID;
/** Sends the answers to simple survey.
 It is mandatory to use this method in order to store the user's responses on the server and collect data.
 @param answer the answers to this survey (see GSSurveyAnswer)
 @param completion a block with no return value that takes two parameters: the answer you sent and wether it was sent successfully or not
 */
- (void)answerSurvey:(SNSurveyAnswer *)answer completion: (void (^)(SNSurveyAnswer *answer, BOOL success))completion;
/** Sends the answers to survey.
 It is mandatory to use this method in order to store the user's responses on the server and collect data.
 @param plusAnswer the answers to this survey (see GSSurveyPlusAnswer)
 @param completion a block with no return value that takes two parameters: the answer you sent and wether it was sent successfully or not
 */
- (void)answerSurveyPlus:(SNSurveyPlusAnswer *)plusAnswer completion:(void (^)(SNSurveyPlusAnswer *answer, BOOL success))completion;
/** Notifies the server that a push notification was opened. You should invoke this when a user enters your app from a remote notification in order to track it from your Dashboard.
 @param pushID the "push_id" string returned inside the APNS payload
 */
- (void)trackPushTap:(NSString*)pushID;

+ (SNBeaconManager *)sharedInstance;   // class method to return the singleton object
- (void)setPushSenderId:(NSString *)pushSenderId;
/** Starts the manager.
 This method will initialize a new SNBeaconRadar using the configuration retrieved from the server. */
- (void)start;
/** Starts the beacon manager in Test Mode
 This method will initialize a new SNBeaconRadar using the configuration retrieved from the server.
 @param view the view that will display the test mode simulator view, which allows you to send fake events and test the framework without using real beacons */
- (void)startWithTestModeOn:(UIView*)view;
- (void)stop;
/** Initiliazes the beacon manager with the supplied Client Token.
 @param token your client token, (e.g. acmelt224501982) */
- (id)initWithToken:(NSString *)token;
+ (void)enablePushNotifications;
/** Updates the data for the current user
 @param name the first name of the user
 @param surname the last name of the user
 @param picture the URL of the user's display picture
 @param reconciliationKey a unique key that represents the user within another datastore. For example if your app connects to your own service through a login mechanism you can use your uid as a unique key to identify the user
 @param completion a block object that acts as the completion handler for the update operation, it has no return value and takes a single BOOL argument indicating wether the configuration was updated or not.
 */
- (void)updateUserDataWithName:(NSString *)name surname:(NSString *)surname picture:(NSString *)picture reconciliationKey:(NSString *)reconciliationKey completion: (void (^)(BOOL success))completion;
/** Logs out the current user
 @param completion a block object that acts as the completion handler for the update operation, it has no return value and takes a single BOOL argument indicating wether the configuration was updated or not.
 */
- (void)userLogout:(void (^)(BOOL success))completion;
- (void)clearData;
/** Retrieves the content associated to the for the push notification, if any.
 As the framework requires to retrieve it remotely the app should not expect a push notification to have any content until the completion handler is called and returns it.
 @param notificationDic the NSDictionary for the push notification as provided by iOS (e.g. the userInfo variable in application:didReceiveRemoteNotification:
 @param completion a block with no return value that takes two parameters: the content for the push notification (if any) and wether the content was fetched properly or not
 */
- (void)getContentForPush:(NSDictionary *)notificationDic completion: (void (^)(NSDictionary *pushContent, BOOL success))completion;

@end
