//
//  GSBeaconDynamicData.h
//  AZVeicoli
//
//  Created by Gioca4 on 09/09/14.
//  Copyright (c) 2014 Gioca Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNBeaconProximity.h"

@interface SNBeaconDynamicData : NSObject

@property (nonatomic, strong) SNBeaconProximity *beacon;
@property (nonatomic, strong) CLBeacon *clBeacon;
@property (nonatomic, strong) NSMutableArray *distances;
@property (nonatomic, strong) NSNumber *average;
@property (nonatomic) double movementTolerance;

- (void)initializeCycleData;
- (void)saveDistance:(NSNumber*)distance;
- (NSNumber*)makeAverage;
- (BOOL)hasMinumumData;

@end
