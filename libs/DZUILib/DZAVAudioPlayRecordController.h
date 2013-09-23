//
//  DZAVAudioPlayRecordController.h
//  DZUILib
//
//  Created by Simon Kim on 12. 3. 3..
//  Copyright (c) 2012년 DZPub.com. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
@class DZAVAudioPlayRecordController;

@protocol DZAVAudioPlayRecordControllerDelegate <NSObject>
- (void) audioController:(DZAVAudioPlayRecordController *) audioController didBeginPlayback:(BOOL) playback;    // or recording
- (void) audioController:(DZAVAudioPlayRecordController *) audioController didFinishPlayback:(BOOL) playback;   // or recording
- (void) audioController:(DZAVAudioPlayRecordController *) audioController didPausePlayback:(BOOL) playback;   // or recording
- (void) audioController:(DZAVAudioPlayRecordController *) audioController didResumePlayback:(BOOL) playback;   // or recording
@end

@interface DZAVAudioPlayRecordController : NSObject
@property (nonatomic, strong) NSURL *urlRecordingFile;
@property (nonatomic, assign) id<DZAVAudioPlayRecordControllerDelegate> delegate;
@property (nonatomic, readonly) BOOL recording;
@property (nonatomic, readonly) BOOL playing;
@property (nonatomic, readonly) AVAudioRecorder *recorder;
@property (nonatomic, readonly) AVAudioPlayer *player;
@property (nonatomic, strong, readonly) NSURL *defaultURLForRecordingFile;

- (BOOL) prepareToRecord;
- (BOOL) startRecordingForDuration:(NSTimeInterval) maxDuration;
- (void) stopRecording;

- (BOOL) prepareAudioSessionForPlayback;
- (BOOL) startPlaybackWithURL:(NSURL *) url;
- (void) stopPlayback;
- (void) pausePlayback;
- (void) resumePlayback;
- (BOOL) simplyPlayAudioAtURL:(NSURL *) url;

@end
