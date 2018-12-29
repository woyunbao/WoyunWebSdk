//
//  WYSDKWebViewTool.h
//  WoyunWebSdk
//
//  Created by 黄志强 on 2018/8/23.
//  Copyright © 2018年 woyunsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "WYSDKWebShareHeader.h"

typedef NS_ENUM(NSUInteger, WYSDKWebEnvironment) {
    WYSDKWebEnvironmentDebug,         // 测试环境
    WYSDKWebEnvironmentRelease,       // 正式环境
};

@protocol WYSDKWebViewDelegate <NSObject>

/**
 令牌授权失败回调

 @param webView 当前网页（有可能为空）
 @param handler 使用方获取用户信息后回调处理
 */
- (void)webView:(WKWebView *)webView authTokenFailCompleteHandler:(void (^)(NSDictionary *info))handler;

@optional

/**
 分享回调
 
 @param webView 网页
 @param shareType 分享类型
 @param mediaType 媒体类型
 @param shareModel 分享数据
 @param handler 分享结果回调
 */
- (void)webView:(WKWebView *)webView shareWithShareType:(WYSDKWebShareType)shareType mediaType:(WYSDKWebShareMediaType)mediaType shareModel:(WYSDKShareBaseModel *)shareModel shareCompleteHandler:(void(^)(BOOL isSuccess, NSString *errorMsg))handler;


/**
 调起微信小程序

 @param webView 网页
 @param userName 拉起的小程序的username
 @param path 拉起小程序页面的可带参路径，不填默认拉起小程序首页
 @param callback 小程序返回APP回调
 */
- (void)webView:(WKWebView *)webView launchWXMiniProgramWithUserName:(NSString *)userName path:(NSString *)path callback:(void(^)(NSString *result))callback;

/**
 其他的回调原生方法

 @param webView 网页
 @param obj 脚本消息内容， 为一个数组对象。格式为 ['约定类型', '约定json内容']， 比如客服: obj = @['customerService', '{"serviceNum": "993497"}']
 */
- (void)webView:(WKWebView *)webView otherCallNativeObj:(id)obj;


@end


@interface WYSDKWebViewTool : NSObject

+ (instancetype)shareManager;

/**
 初始化授权

 @param environment 初始化环境
 */
- (void)authWithEnvironment:(WYSDKWebEnvironment)environment delegate:(id<WYSDKWebViewDelegate>)delegate;

/**
 白名单 默认没有白名单，如果设置了白名单，不在白名单网页将会被拦截
 */
@property (nonatomic, strong) NSArray *whitelist;

/**
 是否需要手势退出，默认支持手势右滑退出
 */
@property (nonatomic, assign) BOOL gesturesExit;

// MARK: - 加载网页

/**
 通过产品id加载网页

 @param productId 产品id
 @param params 额外参数（没有就传空）
 */
- (void)loadWebWithProductId:(NSString *)productId params:(nullable NSDictionary *)params;

/**
 加载网页，标题自适配

 @param url 网页链接
 */
- (void)loadWebWithURL:(NSString *)url;

/**
 加载网页，标题自定义

 @param url 网页链接
 @param customTitle 自定义的标题
 */
- (void)loadWebWithURL:(NSString *)url customTitle:(NSString *)customTitle;


@end
