
#import <Foundation/Foundation.h>

/** Represents an open ended question in a survey, it allows the user to type in their response freely as opposed to choosing an answer from a set list
 */
@interface SNOpenQuestion : NSObject

/** The ID of the question being asked */
@property (nonatomic, strong) NSString *questionID;
//@property (nonatomic, strong) NSString *question;
/** The answer provided by the user */
@property (nonatomic, strong) NSString *answer;

- (NSDictionary *)toJSON;

@end
