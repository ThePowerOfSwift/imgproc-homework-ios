//
//  DZIOURLDownloader.h
//  DZUILib
//
//  Created by Simon on 12. 9. 10..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kURLDownloaderDomain    @"URLDownloader Domain"
#define kURLDownloaderErrorUnknown    -1
#define kURLDownloaderErrorCancelled    -2
#define kURLDownloaderErrorInvalidArguments -3
#define kURLDownloaderErrorMultipleDownloadFailed   -4
typedef void (^DZIOURLDownloaderCompletionHandler)(id result, NSError *error);
typedef void (^DZIOURLDownloaderResponseHandler)(NSURLResponse *response);

@interface DZIOURLDownloader : NSObject
@property (nonatomic, strong) NSURL *localTargetURL;

- (id) initWithRemoteURL:(NSURL *) remoteURL;
- (id) initWithRequest:(NSURLRequest *) request;
- (BOOL) startDownloadWithCompletion:(DZIOURLDownloaderCompletionHandler) completionHandler;
- (void) cancelDownload;

+(id) checkURL:(NSURL *) srcURL timeout:(NSTimeInterval) timeoutInterval responseHandler:(DZIOURLDownloaderResponseHandler) responseHandler;
+(id) downloadFromURL:(NSURL *) srcURL completion:(DZIOURLDownloaderCompletionHandler) completion;
+(id) downloadFromURL:(NSURL *) srcURL toURL:(NSURL *) dstURL completion:(DZIOURLDownloaderCompletionHandler) completion;
+(id) downloadWithRequest:(NSURLRequest *) request completion:(DZIOURLDownloaderCompletionHandler) completion;
+(id) downloadWithRequest:(NSURLRequest *) request toURL:(NSURL *) dstURL completion:(DZIOURLDownloaderCompletionHandler) completion responseHandler:(DZIOURLDownloaderResponseHandler) responseHandler;

/*
 results : NSDictionary
 succeed : NSNumber
 failed : NSNumber
 errors : [ null, null, error, null, ...]
 */
+(NSArray *) downloadMultipleFromURLs:(NSArray *) srcURLs toURLs:(NSArray *) dstURLs completion:(DZIOURLDownloaderCompletionHandler) completion;
@end
