
#import <Foundation/Foundation.h>

@interface SNPushTrackData : NSObject

@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) NSString *pushID;
@property (nonatomic, strong) NSString *OS;
@property (nonatomic, strong) NSString *timestamp;

- (NSDictionary *)toJSON;

@end
