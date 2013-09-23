//
//  DZUIWebViewUtility.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 31..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DZUIWebViewUtility : NSObject

+ (id) previewImageHTMLAtURL:(NSURL *) url
             imageReadyBlock:(void (^)(UIImage *image)) imageReadyBlock 
                  errorBlock:(void (^)(NSError *error)) errorBlock; 
@end
