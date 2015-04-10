//
//  GSBeaconRule.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 14/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SNBeaconAction;
@class SNBeaconTrigger;

@interface SNBeaconRule : NSObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSDictionary *action;
@property (nonatomic, strong) NSArray *previousRules;
@property (nonatomic, strong) SNBeaconTrigger *trigger;
@property (nonatomic, strong) NSArray *dataConditions;

+ (SNBeaconRule*)ruleWithJSON:(NSDictionary*)json;

@end
