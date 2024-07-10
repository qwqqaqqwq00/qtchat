# Boost install

```{bash}
cd boost_1_85_0
b2.exe install --toolset=msvc-14.3 \ # msvc可以从vs installer中查看，或者看vs的版本
--build-type=complete \ # 完整构建
--prefix="D:\_MyWork\2024-2024\backend\cpp\qtchat\third-party\boost_1_85_0" \
link=static runtime-link=shared \ # 链接类型（静态库，动态库），运行时通过共享方式
threading=multi debug release \ # 指定多线程编译 编译目标类型
address-model=64 architecture=x86 # 这行在编译时无法确定架构时需要指定架构
```
