//
//  DZWebFeedParser.h
//  SeminarSamples
//
//  Created by Simon Kim on 12. 4. 6..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DZWebFeedParser : NSObject

@property (nonatomic, strong) NSError *error;
@property (nonatomic, readonly) NSArray *items;
@property (nonatomic, readonly) NSArray *imageURLs;

- (BOOL)parseXMLFileAtURL:(NSURL *)URL;

@end
