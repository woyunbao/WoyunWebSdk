//
//  WYSDKShareBaseModel.h
//  WoyunWebSdk
//
//  Created by 黄志强 on 2018/8/7.
//  Copyright © 2018年 woyunsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface WYSDKShareBaseModel : NSObject

@end

// MARK: - 文字
@interface WYSDKShareTextModel : WYSDKShareBaseModel

/**
 文字内容
 */
@property (nonatomic, strong) NSString *text;

@end

// MARK: - 图片类型
@interface WYSDKShareImageModel : WYSDKShareBaseModel

/**
 缩略图
 */
@property (nonatomic, strong) UIImage *thumbImage;

/**
 分享的大图
 */
@property (nonatomic, strong) UIImage *image;

@end


// MARK: - 音乐类型
@interface WYSDKShareMusicModel : WYSDKShareBaseModel

/**
 音乐标题
 */
@property (nonatomic, strong) NSString *title;

/**
 音乐描述
 */
@property (nonatomic, strong) NSString *desc;

/**
 缩略图
 */
@property (nonatomic, strong) UIImage *thumbImage;

/**
 音乐url
 */
@property (nonatomic, strong) NSString *musicUrl;

/**
 低品质音乐url
 */
@property (nonatomic, strong) NSString *musicLowBandUrl;

/**
 音乐数据url
 */
@property (nonatomic, strong) NSString *musicDataUrl;

/**
 低品质音乐数据url
 */
@property (nonatomic, strong) NSString *musicLowBandDataUrl;


@end


// MARK: - 视频类型
@interface WYSDKShareVideoModel : WYSDKShareBaseModel

/**
 视频标题
 */
@property (nonatomic, strong) NSString *title;

/**
 视频描述
 */
@property (nonatomic, strong) NSString *desc;

/**
 缩略图
 */
@property (nonatomic, strong) UIImage *thumbImage;

/**
 视频url
 */
@property (nonatomic, strong) NSString *videoUrl;

/**
 低分辨率视频url
 */
@property (nonatomic, strong) NSString *videoLowBandUrl;

@end



// MARK: - 网页类型
@interface WYSDKShareURLModel : WYSDKShareBaseModel

/**
 标题
 */
@property (nonatomic, strong) NSString *title;

/**
 描述
 */
@property (nonatomic, strong) NSString *desc;

/**
 缩略图
 */
@property (nonatomic, strong) UIImage *thumbImage;

/**
 网页链接
 */
@property (nonatomic, strong) NSString *url;

@end
