//
//  DZWebHTTPPostServiceLocalFileDescription.h
//  DZUILib
//
//  Created by Simon Kim on 12. 5. 18..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DZWebHTTPPostServiceLocalFileDescription : NSObject
@property (nonatomic, strong) NSURL *localURL;  // URL to the local file to be uploaded
@property (nonatomic, strong) NSString *mimeType;   // image/jpeg for example
@property (nonatomic, strong) NSString *formId; // 'fileContents' for example

- (id) initWithURL:(NSURL *) localURL mimeType:(NSString *) mimeType formId:(NSString *) formId;

@end

