//
//  GSBeaconEvent.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 14/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Represents an event triggered by a beacon that matches a rule in your configuration; it provides information about the beacon and the action that the app is supposed to take upon matching its ruleset
 For more information please see XXX (TODO: Link to KB article)
 */

@interface SNBeaconEvent : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSDate *date;
@property (nonatomic, strong) NSString *ruleId;
/** A dictionary describing the action to be taken by the app, for more information about the meaning of individual keys please refer to XXX */
@property (nonatomic, strong) NSDictionary *action;
/** The minor ID of the beacon that triggered the event */
@property (nonatomic) NSInteger beaconMinor;
/** The major ID of the beacon tha triggered the event */
@property (nonatomic) NSInteger beaconMajor;
/** A string indicating the event being triggered, the possible values are as follows
 
 | Value | Meaning                                                                                       |
 |-------|:----------------------------------------------------------------------------------------------|
 | ENTER | The user has entered within range of a beacon matching your Proximity UUID *and* major ID     |
 | LEAVE | The user is no longer within range of *any* beacon matching your Proximiy UUID *and* major ID |
 */
@property (nonatomic, strong) NSString *rawEvent;

- (NSDictionary*)toJsonTrackWithAccessToken:(NSString*)accessToken andClientToken:(NSString*)clientToken;

@end
