
#import <Foundation/Foundation.h>

/** Represents a message to be displayed upong entering or leaving a specific region.
 It will be passed to the SNBeaconManager delegate whenever it's deemed necessary by the framework to diplay a region related message, but it's up to the app wether to display it or not (e.g. if the user is currently doing something they cannot be distracted from or to avoid delivering too many messages). */
@interface SNRegionMessage : NSObject

/** The region event, the possible values are as follows
 
 | Value | Meaning                                                                                       |
 |-------|:----------------------------------------------------------------------------------------------|
 | ENTER | The user has entered within range of a beacon matching your Proximity UUID *and* major ID     |
 | LEAVE | The user is no longer within range of *any* beacon matching your Proximiy UUID *and* major ID |
 
 */
@property (nonatomic, strong) NSString *event;
/** The major ID of the region the user has entered or left */
@property (nonatomic, strong) NSString *major;
/** The title for the message to be displayed */
@property (nonatomic, strong) NSString *title;
/** The body for the message to be displayed */
@property (nonatomic, strong) NSString *message;

+ (SNRegionMessage *)regionMessageWithJSON: (NSDictionary *)jsonDictionary;
@end
