//
//  WYSDKWebShareHeader.h
//  WoyunWebSdk
//
//  Created by 黄志强 on 2018/8/6.
//  Copyright © 2018年 woyunsoft. All rights reserved.
//

#ifndef WYSDKWebShareHeader_h
#define WYSDKWebShareHeader_h
#import "WYSDKShareBaseModel.h"

typedef NS_OPTIONS(NSUInteger, WYSDKWebShareType) {
    WYSDKWebShareTypeWXSceneSession = 1 << 0,     // 微信好友
    WYSDKWebShareTypeWXSceneTimeline = 1 << 1,    // 微信朋友圈
    WYSDKWebShareTypeWXSceneFavorite = 1 << 2,    // 微信收藏
    WYSDKWebShareTypeQR = 1 << 3,                 // 生成链接二维码，仅支持url分享的
};

typedef NS_OPTIONS(NSUInteger, WYSDKWebFuncType) {
    WYSDKWebFuncTypeCopy = 1 << 0,       // 复制链接
    WYSDKWebFuncTypeReload = 1 << 1,     // 刷新
    WYSDKWebFuncTypeAdjustFont = 1 << 2, // 调整字体
    WYSDKWebFuncTypeHistory = 1 << 3,    // 历史记录
};

typedef NS_ENUM(NSUInteger, WYSDKWebShareMediaType) {
    WYSDKWebShareMediaTypeURL,    // 链接
    WYSDKWebShareMediaTypeImage,  // 图片
    WYSDKWebShareMediaTypeMusic,  // 音乐
    WYSDKWebShareMediaTypeVideo,  // 视频
    WYSDKWebShareMediaTypeText    // 文字
};

typedef void(^WYSDKWebShareTypeCallback)(WYSDKWebShareType type, WYSDKShareBaseModel *model);
typedef void(^WYSDKWebFuncTypeCallback)(WYSDKWebFuncType type);



#endif /* WYSDKWebShareHeader_h */
