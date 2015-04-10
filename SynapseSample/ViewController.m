//
//  ViewController.m
//  SynapseSample
//
//  Created by Dario Mendez Musico on 09/04/15.
//  Copyright (c) 2015 MindTek. All rights reserved.
//

#import <Synapse/Synapse.h>

#import "ViewController.h"
#import "ContentViewController.h"

@interface ViewController () <SNBeaconManagerDelegate>
@property (weak, nonatomic) IBOutlet UIView *fakePullView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *notificationConstraint;
@property (weak, nonatomic) IBOutlet UIView *notificationView;
@property (weak, nonatomic) IBOutlet UILabel *notificationTitle;
@property (weak, nonatomic) IBOutlet UILabel *notificationBody;
@property (weak, nonatomic) IBOutlet UIButton *notificationButton;
@property (weak, nonatomic) IBOutlet UIButton *ignoreButton;
@property BOOL animating;

@property (weak, nonatomic) IBOutlet UILabel *radarStatus;

@property NSString *content;

@property (nonatomic, strong) SNBeaconManager *beaconManager;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _notificationView.hidden = YES;
    _radarStatus.hidden = YES;
    
    _content = @"__START__";
    [self showNotificationWithTitle:@"Welcome" body:@"We hope you enjoy our application, for feedback please get in touch hello@synapse-manager.io" buttonTitle:@"Start radar"];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)notificationButtonTapped:(id)sender {
    [self hideNotification];
    if (_content != nil)
    {
        if ([_content isEqualToString: @"__START__"])
        {
            self.beaconManager = [[SNBeaconManager alloc] initWithToken:@"mindtek123456789"];
            self.beaconManager.managerDelegate = self;
            [self.beaconManager updateConfiguration:^(BOOL success) {
                //[self.beaconManager startWithTestModeOn:self.view];
                [self.beaconManager start];
                
                dispatch_async(dispatch_get_main_queue(), ^{
                    _radarStatus.text = [NSString stringWithFormat:@"Listening for beacons on %@...", self.beaconManager.configuration.majors[0]];
                    _radarStatus.hidden = NO;
                });
            }];
        } else {
            [self performSegueWithIdentifier:@"showContent" sender:self];
        }
    }
}

- (IBAction)test:(id)sender {
    _content = nil;
    [self showNotificationWithTitle:@"Hey there!" body:@"Looks like you like notifications, so here's another one for the road.\n♥︎, your pals at MindTek" buttonTitle: @"Thanks"];
}

- (IBAction)unwindToMainView:(UIStoryboardSegue*)sender
{
    
}

#pragma mark Beacon Events
- (void)notifyEnterRegion:(CLBeaconRegion *)region
{
    
}

- (void)notifyExitRegion:(CLBeaconRegion *)region
{
    
}

- (void)notifyBeaconEvent:(SNBeaconEvent *)event
{
    NSLog(@"Action: %@", event.action);
    if ([event.action objectForKey:@"title"] != nil || [event.action objectForKey:@"message"] != nil)
    {
        _content = [event.action objectForKey:@"text"];
        [self showNotificationWithTitle:[event.action objectForKey:@"title"] body:[event.action objectForKey:@"message"] buttonTitle:(_content != nil)? @"Open" : @"OK"];
    }
}

- (void)notifyBeaconError:(NSError *)error
{
    
}

#pragma mark In-App Notifications
- (void)showNotificationWithTitle:(NSString*)title body:(NSString*)body buttonTitle:(NSString *)buttonTitle
{
    if (_notificationView.hidden && !_animating)
    {
        //_content = nil;
        if (!_content || [_content isEqualToString:@"__START__"])
        {
            _ignoreButton.hidden = YES;
        } else {
            _ignoreButton.hidden = NO;
        }
        
        _notificationTitle.text = title;
        _notificationBody.text = body;
        [_notificationButton setTitle:buttonTitle forState:UIControlStateNormal];
        _notificationConstraint.constant = 0-_notificationView.frame.size.height;
        _notificationView.hidden = NO;
        
        _animating = YES;
        [self.view layoutIfNeeded];
        //[UIView animateWithDuration:2 animations:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            _fakePullView.hidden = NO;
        });
        [UIView animateWithDuration:0.5 delay:0 usingSpringWithDamping:0.6 initialSpringVelocity:1 options:0 animations:^{
            _notificationConstraint.constant = 0;
            [self.view layoutIfNeeded];
        } completion:^(BOOL finished) {
            _fakePullView.hidden = YES;
            _animating = YES;
        }];
    }
}

- (IBAction)ignoreNotification:(id)sender {
    [self hideNotification];
}

- (void)hideNotification
{
    _animating = YES;
    _fakePullView.hidden = NO;
    [self.view layoutIfNeeded];
    [UIView animateWithDuration:0.3 animations:^{
        _notificationConstraint.constant = 20;
        [self.view layoutIfNeeded];
    } completion:^(BOOL finished) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 0.1 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            _fakePullView.hidden = YES;
        });
        [self.view layoutIfNeeded];
        [UIView animateWithDuration:0.2 animations:^{
            _notificationConstraint.constant = 0-_notificationView.frame.size.height;
            [self.view layoutIfNeeded];
        } completion:^(BOOL finished) {
            _notificationView.hidden = YES;
            _animating = NO;
        }];
    }];
}

#pragma mark Navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString: @"showContent"])
    {
        ContentViewController *destinationVC = segue.destinationViewController;
        destinationVC.content = _content;
    }
}

@end
