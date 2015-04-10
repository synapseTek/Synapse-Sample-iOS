//
//  GSBeaconDynamicRadar.h
//  AZVeicoli
//
//  Created by Gioca4 on 09/09/14.
//  Copyright (c) 2014 Gioca Srl. All rights reserved.
//

#import "SNBeaconRadar.h"
#import "SNBeaconProximity.h"
#import "SNBeaconDynamicData.h"

@protocol SNBeaconDynamicRadarDelegate<NSObject>

@optional
- (void)radarDidChangeDistances:(NSArray*)distances;

@end

@interface SNBeaconDynamicRadar : SNBeaconRadar

@property (nonatomic) double variance;
@property (nonatomic, weak) id<SNBeaconDynamicRadarDelegate> dynamicDelegate;

- (void)updateMovementTolerance:(double)tolerance;

@end
