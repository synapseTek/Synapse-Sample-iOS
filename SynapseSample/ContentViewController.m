//
//  ContentViewController.m
//  SynapseSample
//
//  Created by Dario Mendez Musico on 10/04/15.
//  Copyright (c) 2015 MindTek. All rights reserved.
//

#import "ContentViewController.h"

@interface ContentViewController ()
@property (weak, nonatomic) IBOutlet UITextView *contentView;

@end

@implementation ContentViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _contentView.attributedText = [[NSAttributedString alloc] initWithData:[_content dataUsingEncoding:NSUnicodeStringEncoding] options:@{ NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType } documentAttributes:nil error:nil];
}

@end
