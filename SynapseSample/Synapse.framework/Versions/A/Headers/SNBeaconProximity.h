//
//  GSProximity.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 14/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/** This class represents a beacon that has been set up in your account */
@interface SNBeaconProximity : NSObject

/** The major ID of the beacon */
@property (nonatomic, copy) NSNumber *major;
/** The minor ID of the beacon */
@property (nonatomic, copy) NSNumber *minor;
/** An integer representing how close a user needs to be in order for the beacon to start registering events, it has three possible values
 
 | Value | Meaning                                        |
 |-------|:-----------------------------------------------|
 | 0     | Immediate (within 20 centimeters)              |
 | 1     | Near (within 3 meters)                         |
 | 2     | Far (as far as the beacon can still be ranged) |
 
*/
@property (nonatomic) NSInteger proximity;

+ (NSInteger)integerFromProximity:(CLProximity)proximity;
+ (SNBeaconProximity*)proximityWithJSON:(NSDictionary*)json;

@end
