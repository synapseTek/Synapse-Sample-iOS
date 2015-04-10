//
//  MTStoreNetworkManager.h
//  AZVeicoli
//
//  Created by Gioca4 on 30/10/14.
//  Copyright (c) 2014 Gioca Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MTStoreNetworkManager : NSObject

- (void)addPOSTRequestURL:(NSURL*)url forData:(NSData*)data;
- (BOOL)persistQueue;
- (void)processQueue;
+ (MTStoreNetworkManager*)sharedManager;

@end
