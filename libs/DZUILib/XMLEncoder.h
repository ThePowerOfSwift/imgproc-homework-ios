//
//  XMLEncoder.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 30..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XMLEncoder : NSObject

- (void)appendString:(NSString *)aString;
- (void)appendFormat:(NSString *)format, ... ;
// <tag>value</tag>
- (void) appendTag:(NSString *) tag withValue:(NSString *) value;
- (void)encodeInputStream: (NSInputStream *)stream;

- (NSNumber *)encodedLength;
- (void) cleanupStreamingCache;
- (void) synchronizeStreamingCache;
- (NSOutputStream *) outputStream;
- (NSInputStream *) inputStreamForStreamingCache;
- (NSData *) dataFromStreamingCache;

+ (void) dumpNSURLRequest:(NSURLRequest *) request;

+ (void) appendString:(NSString *)string toData:(NSMutableData *)data;

+ (NSString *)escapedString:(NSString *) inputString;

@end
