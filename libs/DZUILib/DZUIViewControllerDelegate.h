//
//  DZUIViewControllerDelegate.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 14..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

// Defines very common UIViewController Delegate for don/cancel
@protocol DZUIViewControllerDelegate <NSObject>
- (void) commonViewControllerDone:(UIViewController *) viewController;
@optional
- (void) commonViewControllerDidCancel:(UIViewController *) viewController;
@end
