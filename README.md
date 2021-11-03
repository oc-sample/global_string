# global_string


​
假定使用场景：需要在头文件定义一个公共常量字符串，供其它文件使用

 

方式1-使用std::string

例子：const std::string kPackageTypeDebug = "debug_string";

缺点：当存在多个.cc文件引用公共头文件的情况下， 会创建多份相同内容的std::string，而且会导致多次全局初始化创建std::string

测试结果如下：

print version debug_string 63da38 teacher
print version debug_string 63da68 student
print version debug_string 63da20 car

方式2-使用const 字符串数组
例子：const char kPackageTypeDebug[] = "debug_array";

缺点：当存在多个.cc文件引用公共头文件的情况下，会导致模块镜像存在多份内容相同的字符串拷贝 



测试结果：

print version debug_array 4b37de8 4b37de8 teacher
print version debug_array 4b37e0a 4b37e0a student
print version debug_array 4b37ddc 4b37ddc car

方式3-使用const 字符串指针

例子：static const char* kPackageTypeDebug = "debug_pointer_static";

缺点：当存在多个.cc文件引用公共头文件的情况下，会存在多份指针拷贝。如果该定义是在动态库的导出头文件，还会导致存在多份内容拷贝

测试结果：

print version debug_pointer_static d5a40f d5d8f0 teacher
print version debug_pointer_static d5a40f d5d908 student
print version debug_pointer_static d5a40f d5d828 car

方式4-使用指针分开定义和实现字符串常量

.h
extern const char* kPackageTypeDebug;

.cc
const char* kPackageTypeDebug = "debug_pointer_extern";

描述：常量字符串的定义的最佳方式，保证只有一份字符串定义

测试结果：

