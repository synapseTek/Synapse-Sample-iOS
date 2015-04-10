
#import <Foundation/Foundation.h>

/** This class represnts a client configuration, it is mostly meant to be used autonomously by the framework but the app can use it in order to obtain more information.
    Configuration should never be altered manually by the app and should instead be updated by calling updateConfiguration: on the app's SNBeaconManager.
 */
@interface SNBeaconConfiguration : NSObject

/** An array containing all the configured beacons */
@property (nonatomic, strong) NSArray *proximities;
/** An array containing all the rules */
@property (nonatomic, strong) NSArray *rules;
/** An array containing all the major ID's */
@property (nonatomic, strong) NSArray *majors;
/** An array containing the region messages */
@property (nonatomic, strong) NSArray *regionMessages;
/** The proximity UUID */
@property (nonatomic, strong) NSString *uuid;

+ (SNBeaconConfiguration*)configurationWithJSON:(NSDictionary*)json;

@end
