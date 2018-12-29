
Pod::Spec.new do |s|

  s.name         = "WoyunsoftWebSDK"
  s.version      = "1.2"
  s.summary      = "WebSdkLib"
  s.description  = "沃云科技WebSDK"
  s.homepage     = "https://github.com/woyunbao/WoyunWebSdk"
  s.license      = "MIT"
  s.author       = { "黄志强" => "zhiqiangit@126.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.source       = { :git => "https://github.com/woyunbao/WoyunWebSdk.git", :tag => "#{s.version}" }
  s.source_files = "WoyunsoftWebSDK/**/*.*"
  s.ios.vendored_frameworks = "WoyunsoftWebSDK/WoyunWebSdk.framework"

end
