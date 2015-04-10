//
//  GSBeaconPreviousRule.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 15/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SNBeaconPreviousRule : NSObject

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSString *count;
@property (nonatomic, strong) NSString *maxCount;
@property (nonatomic, strong) NSString *minCount;
@property (nonatomic, strong) NSString *minSecondsPassed;
@property (nonatomic, strong) NSString *maxSecondsPassed;
@property (nonatomic, strong) NSString *limit;

+ (SNBeaconPreviousRule*)previousRuleWithJSON:(NSDictionary*)json;

@end
