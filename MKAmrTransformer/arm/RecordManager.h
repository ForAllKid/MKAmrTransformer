//
//  RecordManager.h
//  VoiceRecord
//
//  Created by 好价网络科技有限公司 on 16/1/15.
//  Copyright © 2016年 Grey. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void (^writeSuccessBlock)(BOOL success,NSData *amrData);
typedef void (^progressBlock)(float progress);

@interface RecordManager : NSObject

+(RecordManager*)shareManager;

@property (nonatomic,copy)progressBlock progress;

- (void)writeAuToAmrFile:(NSURL*)tmpFileUrl callback:(writeSuccessBlock)block;

- (BOOL)writeAuToAmrFile:(NSURL*)tmpFileUrl;


/* 存储文件名 */
- (void)startTalkVoice:(NSString*)fileName;

/* 停止返回存储caf的地址 */
- (NSURL*)stopTalkVoice;

/** 暂停录音 */
- (void)pauseVoice;

- (void)continueVoice;

/* 取消录音,删除文件 */
- (void)cancelTalkVoice;

/* 播放amr 文件 */
- (void)playAmrData:(NSData*)amrData;

/* 录音时长 */
- (NSString*)getAudioTime:(NSData *)data;

/* 销毁对象 */
- (void)destroy;
@end
