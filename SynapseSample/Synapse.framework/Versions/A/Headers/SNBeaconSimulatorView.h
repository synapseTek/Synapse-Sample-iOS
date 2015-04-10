//
//  GSBeaconSimulatorView.h
//  EstimoteSDKTest
//
//  Created by Gioca4 on 17/07/14.
//  Copyright (c) 2014 Gioca. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SNBeaconSimulatorViewDelegate

- (void)simulatorSendCommandWithMinor:(NSInteger)minor andRawEvent:(NSInteger)rawEvent;
- (void)simulatorSendEnterRegion;
- (void)simulatorSendLeaveRegion;

@end

@interface SNBeaconSimulatorView : UIView

@property (nonatomic, strong) IBOutlet UITextField *numberTextField;
@property (nonatomic, strong) IBOutlet UISegmentedControl *commandSegment;
@property (nonatomic, weak) id<SNBeaconSimulatorViewDelegate> delegate;

- (IBAction)sendCommand:(id)sender;
- (IBAction)sendEnterRegion:(id)sender;
- (IBAction)sendLeaveRegion:(id)sender;

@end
