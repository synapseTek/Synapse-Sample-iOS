
#import <Foundation/Foundation.h>

/** Represents a simple survey answer. Simple surveys only provide multiple choice questions */
@interface SNSurveyAnswer : NSObject

/** The ID of the question being asked **/
@property (nonatomic, strong) NSString *survey;
/** The ID of the chosen answer **/
@property (nonatomic, strong) NSString *answer;

- (NSDictionary *)toJSON;
@end
