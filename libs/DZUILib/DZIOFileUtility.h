//
//  DZIOFileUtility.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 24..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DZIOFileUtility : NSObject
+ (NSURL *) temporaryCacheFileURL;
+ (NSURL *) uniqueDocumentURL;
+ (NSURL *) URLforDocumentDirectory;
+ (BOOL) createDirectoryAtURL:(NSURL *) URL;
+ (NSString *) uniqueFilenameAtPath:(NSString *) path;

+ (void)fileHandle:(NSFileHandle *) fileHandle appendFormat:(NSString *)format, ... ;
+ (void)fileHandle:(NSFileHandle *) fileHandle appendString:(NSString *)aString;
/*
 + (NSURL *) temporaryFileURL;
 */

@end
