# 简介
> 本文档主要介绍websdk的安装和使用，其中Demo工程中包含完整的集成逻辑，以下文档说明`Objective-C`示例均为Demo工程的例子。
## 支持的系统和硬件版本
- iOS 8.0 以上
- 架构：`i386` `x86_64` `armv7` `arm64`
## 业务流程框架图
![image](https://file-1253685439.cosgz.myqcloud.com/path/2018/12/20181226164950746.png)

# SDK集成教程
## 运行Demo

![image](http://file-1253685439.cosgz.myqcloud.com/document/ios_websdk/WX20180824-154423%402x.png)

以Demo为例，点击运行，搞定

![image](https://file-1253685439.cosgz.myqcloud.com/path/2018/12/20181225122132890.png)

## 项目集成
新建项目MyFirst

![image](http://file-1253685439.cosgz.myqcloud.com/document/ios_websdk/WX20180827-142434%402x.png)

引入sdk，这里需要注意的是由于我们使用的是dynamic framework，在引入到工程之中时，必须引入到Embedded Binaries这里

![image](http://file-1253685439.cosgz.myqcloud.com/document/ios_websdk/WX20180827-142836%402x.png)
![image](http://file-1253685439.cosgz.myqcloud.com/document/ios_websdk/WX20180827-143252%402x.png)
![image](http://file-1253685439.cosgz.myqcloud.com/document/ios_websdk/WX20180827-143336%402x.png)

## 使用cocoapod集成
参考demo工程，点击查看websdk[私有库地址](https://gitee.com/woyunsoft/WebSdkLib.git)

## 接口调用

### 1、初始化

`Swift`
```
import WoyunWebSdk

// 初始化
WYSDKWebViewTool.shareManager()?.auth(with: WYSDKWebEnvironment.debug, delegate: self)
```
`Objective-C`
```
#import <WoyunWebSdk/WoyunWebSdk.h>

// 初始化
[[WYSDKWebViewTool shareManager] authWithEnvironment:WYSDKWebEnvironmentDebug delegate:self];
```
### 2、实现代理方法
#### 授权回调，__必须实现__，因为在初始化的时候会使用到授权信息！

`Swift`
```
// 授权回调处理，必须实现
func webView(_ webView: WKWebView!, authTokenFailCompleteHandler handler: (([AnyHashable : Any]?) -> Void)!) {
// 获取授权信息
let info = ["token": "eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiJlYzBiODkxMS0yZjcwLTRjYjItYjdlNC04YzExZmVkMjQwYjkiLCJpYXQiOjE1NDU2Mzg1ODYsInN1YiI6IjE3MDE3MzAwODI2IiwiZXhwIjoxNTQ1NzI0OTg2fQ.cA2fhb5MP81anuOECD-2vxWxS0oRCS_pIt3ozQpmwos-1545638586173", "id": "3"]

// 获取完成后回调
handler(info)
}
```
`Objective-C`
```
- (void)webView:(WKWebView *)webView authTokenFailCompleteHandler:(void (^)(NSDictionary *))handler {
// 这里获取新的token和agentId
[self.viewModel verificateComplete:^(BOOL isSuccess, NSDictionary * _Nonnull result, NSString * _Nonnull errorMsg) {
if (isSuccess) {
handler(result);
}
}];
}
```

#### 分享回调
`Swift`
```
func webView(_ webView: WKWebView!, shareWith shareType: WYSDKWebShareType, mediaType: WYSDKWebShareMediaType, share shareModel: WYSDKShareBaseModel!, shareCompleteHandler handler: ((Bool, String?) -> Void)!) {
// 这里处理分享
// ......
// 分享完成后回调
handler(true, nil)
}
```
`Objective-C`
```
- (void)webView:(WKWebView *)webView shareWithShareType:(WYSDKWebShareType)shareType mediaType:(WYSDKWebShareMediaType)mediaType shareModel:(WYSDKShareBaseModel *)shareModel shareCompleteHandler:(void (^)(BOOL, NSString *))handler {

[[WoyunWXTool shareManager] shareTo:shareType mediaType:mediaType shareModel:shareModel completeHandle:handler];
}
```

#### 调起小程序
`Swift`
```
// 唤起小程序
func webView(_ webView: WKWebView!, launchWXMiniProgramWithUserName userName: String!, path: String!, callback: ((String?) -> Void)!) {
// 唤起后回调结果
callback("{}")
}
```
`Objective-C`
```
- (void)webView:(WKWebView *)webView launchWXMiniProgramWithUserName:(NSString *)userName path:(NSString *)path callback:(void (^)(NSString *))callback {
// 唤起后回调结果
[[WoyunWXTool shareManager] launchMiniProgramWithUserName:userName path:path callback:callback];
}
```
#### 其他交互方法
> `obj`是脚本消息内容，为一个数组对象。格式为 ['约定类型', '约定json内容']  
> 比如客服: `obj = @['customerService', '{"serviceNum": "993497"}']`

`Swift`
```
// 其他的H5调用原生方法
func webView(_ webView: WKWebView!, otherCallNativeObj obj: Any!) {

}
```
`Objective-C`
```
// 其他的H5调用原生方法
- (void)webView:(WKWebView *)webView otherCallNativeObj:(id)obj {

}
```

### 3、开始使用 
#### 通过API加载网页
`Swift`
```
let productId = "175367770186190848"
// 需要添加额外参数的加载(会拼接在实际链接参数)
WYSDKWebViewTool.shareManager()?.loadWeb(withProductId: productId, params: ["callback": "123"])
```
`Objective-C`
```
// 产品id
NSString *productId = @"175367770186190848";
[[WYSDKWebViewTool shareManager] loadWebWithProductId:productId params:nil];
```
#### 普通链接加载
`Swift`
```
WYSDKWebViewTool.shareManager()?.loadWeb(withURL: "https://www.woyunsoft.com")
```
`Objective-C`
```
[[WYSDKWebViewTool shareManager] loadWebWithURL:@"https://www.woyunsoft.com"];
```
## 上传App Store
> 使用动态库有诸多优势，但若在动态库包含多个架构，在上传AppStore前需要删除模拟器架构

为了方便开发者调试，我们使用lipo工具合并了模拟器和真机的架构。所以在上传前AppStore前，必须使用lipo移除模拟器的架构，否则会报错：
```
ERROR ITMS-90087: "Unsupported Architectures. The executable for MyFirst.app/Frameworks/WoyunWebSdk.framework contains unsupported architectures '[x86_64, i386]'."
```

我们使用lipo工具移除模拟器架构即可。详细的操作方法已经在文档最后的FAQ中列出。



# 版本更新记录
|上线日期|版本号|更新内容|
|----|-----|-------------|
|2018.12.25|1.2|精简对接流程，初始化方法更改|
|2018.12.21|1.1|授权模式换成token授权|
|2018.08.27|1.0|第一版|

# FAQ
1、直接运行无问题，但Archive/IPA/Upload AppStore 时报错``"Unsupported Architecture. Your executable contains unsupported architecture '[x86_64, i386]..."``

为了方便开发者调试，WoyunWebSdk.framework合并了模拟器和真机架构，上线之前，使用lipo工具移除相关架构即可，参考：
```
# 使用lipo -info 可以查看包含的架构
lipo -info WoyunWebSdk.framework/WoyunWebSdk  # Architectures in the fat file: WoyunWebSdk.framework/WoyunWebSdk are: i386 x86_64 armv7 arm64 

# 移除i386，x86_64
lipo -remove x86_64 WoyunWebSdk.framework/WoyunWebSdk
lipo -remove i386 WoyunWebSdk.framework/WoyunWebSdk

# 再次查看
lipo -info WoyunWebSdk.framework/WoyunWebSdk  # Architectures in the fat file: WoyunWebSdk.framework/WoyunWebSdk are: armv7 arm64 
```
