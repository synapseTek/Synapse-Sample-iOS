//
//  GSBeaconRadar.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 07/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "SNBeaconSimulatorView.h"
#import "SNBeaconSimulation.h"

@class SNBeaconSimulatorView;

/** The Beacon Radar Delegate protocol is used to allow communication between a beacon radar, which takes care of the actual ranging and detection, and the beacon manager, which evaluates rules against your configuration 
 You should **not** set your SNBeaconRadar's delegate to anything other than a SNBeaconManager
 */
@protocol SNBeaconRadarDelegate

- (void)enterForBeacon:(CLBeacon*)beacon atTime:(NSDate*)date;
- (void)leaveForBeacon:(CLBeacon*)beacon atTime:(NSDate*)date;
- (void)radarDidFailWithError:(NSError*)error;
- (void)radarDidEnterInRegion:(CLBeaconRegion*)region;
- (void)radarDidExitInRegion:(CLBeaconRegion*)region;

@end

/** The Beacon Radar is the class that takes care of detecting beacons and locating the user in relation to their position inside beacon delimited areas, it is imperative that you have at least one beacon radar active in order for your application to offer location based functionality
Once you have instantiated your beacon radar you must make sure you set its delegate to your Beacon Manager, as they are designed to work together
Please note that you do *not* need to manage beacon radars yourself, but using the SNBeaconManager's start: method a beacon radar is created and started for you using your configuration.
*/
@interface SNBeaconRadar : NSObject<SNBeaconSimulatorViewDelegate, CLLocationManagerDelegate>

/** The major that the beacon radar is monitoring, it must be one of the majors assigned to your account */
@property (nonatomic) NSInteger regionMajor;
@property (nonatomic, strong) CLBeacon *currentBeacon;
/** An array containing all the beacons the radar will work with, it is recommended that you pass your beacon manager configuration's proximities array */
@property (nonatomic, strong) NSArray *proximities;
/** The delegate that will receive the raw events, this should be your beacon manager */
@property (nonatomic, strong) id<SNBeaconRadarDelegate> radarDelegate;
//@property (nonatomic, strong) ESTBeaconManager *beaconManager;
/** Indicates that the radar is in test mode and can generate fake beacon events */
@property (nonatomic) BOOL testMode;
@property (nonatomic) CLLocationManager *locationManager;
/** The UUID of the beaons being ranged by this radar */
@property (nonatomic, strong) NSUUID *proximityUUID;

/** The initializer for this class
 @param proximities an NSArray containing the beacons for your account, you should pass your beacon manager configuration's proximities array in order to make sure it's in sync with your account's settings
 */
- (id)initWithProximities:(NSArray*)proximities;

- (void)enterBeacon:(CLBeacon *)beacon;
- (void)leaveBeacon:(CLBeacon *)beacon;
- (void)startRanging;
- (void)stopRanging;
/** Instructs the radar to start monitoring your beacons */
- (void)startMonitoring;
/** Instructs the radar to stop monitoring your beacons. Your app will no longer receive beacon events until you invoke startMonitoring again */
- (void)stopMonitoring;
- (void)beaconsDiscovered:(NSArray*)beacons;
/** Shows a small view you can use to simulate enter and leave region events and input a minor to simulate ENTER and LEAVE events for that beacon.
 @warning **Warning:** while the view will appear regardless it will only work as long as the radar's testMode property is set to YES.
 @param view the view the simulator will appear in
 @param originY the Y coordinate of the simulator view
 */
- (SNBeaconSimulatorView*)showSimulatorInView:(UIView*)view withOriginY:(CGFloat)originY;
- (void)requestAlwaysAuthorization;

@end
