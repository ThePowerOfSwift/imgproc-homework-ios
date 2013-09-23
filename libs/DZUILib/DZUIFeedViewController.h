//
//  DZUIFeedViewViewController.h
//  SeminarSamples
//
//  Created by Simon Kim on 12. 4. 6..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>


@class DZUIFeedViewController;

@protocol DZUIFeedViewControllerDelegate <NSObject>
- (void) feedViewControllerDone:(DZUIFeedViewController *) feedViewController;
@end

@interface DZUIFeedViewController : UITableViewController
@property (nonatomic, strong) NSURL *feedURL;
@property (nonatomic, weak) id<DZUIFeedViewControllerDelegate> delegate;
@end
