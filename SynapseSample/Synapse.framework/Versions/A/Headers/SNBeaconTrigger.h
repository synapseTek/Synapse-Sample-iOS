//
//  GSBeaconTrigger.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 15/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SNBeaconTrigger : NSObject

@property (nonatomic, strong) NSString *rawEvent;
@property (nonatomic, strong) NSString *minor;
@property (nonatomic, strong) NSString *major;
@property (nonatomic, strong) NSArray *beacons;

+ (SNBeaconTrigger*)triggerWithJSON:(NSDictionary*)json;

@end
