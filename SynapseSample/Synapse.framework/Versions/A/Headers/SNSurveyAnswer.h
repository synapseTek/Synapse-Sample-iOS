
#import <Foundation/Foundation.h>

/** Used to respond to surveys received through the Synapse Framework; in order to do so the app is required to create a new instance of this class and populate it with the user's responses.
 */
@interface SNSurveyAnswer : NSObject

/** The ID of the survey */
@property (nonatomic, strong) NSString *survey; //ID
/** An NSMutableArray containing SNOpenQuestion instances, each representing a response to an open ended question in the survey */
@property (nonatomic, strong) NSMutableArray *openQuestions;
/** An NSMutableArray containing SNClosedQuestion instances, each representing a response to a multiple choice question in the survey */
@property (nonatomic, strong) NSMutableArray *surveys;

- (NSDictionary *)toJSON;

@end
