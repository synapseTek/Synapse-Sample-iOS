//
//  MTStoreObject.h
//  AZVeicoli
//
//  Created by Gioca4 on 30/10/14.
//  Copyright (c) 2014 Gioca Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MTStoreObject : NSObject<NSCoding>

@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) NSData *data;
@property (nonatomic, strong) NSString *method;
@property (nonatomic) NSInteger numberOfFails;
@property (nonatomic, strong) NSDate *lastTimeFail;
@property (nonatomic, strong) NSDate *bornDate;

- (BOOL)isFailed;
- (void)setFailed;
- (BOOL)isExpired;

@end
