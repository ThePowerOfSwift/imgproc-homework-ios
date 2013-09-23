//
//  EntryViewController.h
//  LogEverything_Prototype
//
//  Created by Simon Kim on 09. 11. 18..
//  Copyright 2009 DZPub.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DZUIEntryViewController;

@protocol DZUIEntryViewControllerDelegate <NSObject>
- (void)entryViewControllerCanceled:(id<DZUIEntryViewController>)entryViewController;
- (void)entryViewControllerDone:(id<DZUIEntryViewController>)entryViewController;
@end

@protocol DZUIEntryViewController <NSObject>
@property (nonatomic, assign) id<DZUIEntryViewControllerDelegate> delegate;
@end
