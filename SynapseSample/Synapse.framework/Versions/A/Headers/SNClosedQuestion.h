

#import <Foundation/Foundation.h>

/** Represents a question in a survey, it allows the user to choose their response from a set list of answers
 */
@interface SNClosedQuestion : NSObject
/** The ID of the question being asked */
@property (nonatomic, strong) NSString *questionID;
/** The ID of the answer chosen by the user */
@property (nonatomic, strong) NSString *answerID;

- (NSDictionary *)toJSON;

@end
