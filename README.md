# global_string
## 解决问题
定义一个公共常量字符串供其它文件使用的几种方法对比

## 方式1-std::string
### 错误语法：
std::string kPackageTypeDebug = "debug_string";
错误提示：duplicate symbol
### 正确语法：
const std::string kPackageTypeDebug = "debug_string";
static const std::string kPackageTypeDebug = "debug_string";
缺点：头文件被.cc文件引用多少次就会创建多少份相同内容的std::string，并且会导致多次调用std::string的构造函数，影响启动时间
### 测试结果
print version debug_string 63da38 teacher
print version debug_string 63da68 student
print version debug_string 63da20 car

## 方式2-const 字符串数组
### 错误语法
char kPackageTypeDebug[] = "debug_array";
### 正确语法
const char kPackageTypeDebug[] = "debug_array";
static const char kPackageTypeDebug[] = "debug_array";
缺点：头文件被.cc文件引用多少次，会导致模块镜像存在多份内容相同的字符串拷贝，字符串拷贝存在__TEXT,__const段

### 测试结果：
print version debug_array 4b37de8 4b37de8 teacher
print version debug_array 4b37e0a 4b37e0a student
print version debug_array 4b37ddc 4b37ddc car

## 方式3-const 字符串指针
### 错误语法
const char* kPackageTypeDebug = "debug_pointer_static";
### 正确语法
static const char* kPackageTypeDebug = "debug_pointer_static";
const char* const kPackageTypeDebug = "debug_pointer_double_const";
缺点：头文件被.cc文件引用多少次，会存在多份指针拷贝。如果变量定义在动态库的导出头文件，还会导致存在多份内容拷贝

### 测试结果：
print version debug_pointer_static d5a40f d5d8f0 teacher
print version debug_pointer_static d5a40f d5d908 student
print version debug_pointer_static d5a40f d5d828 car

## 方式4-字符串指针定义(.h)和实现分离(.cc)
### 正确语法
.h
extern const char* kPackageTypeDebug;
.cc
const char* kPackageTypeDebug = "debug_pointer_extern";
描述：常量字符串的定义的最佳方式，保证只有一份字符串定义

测试结果：
print version debug_pointer_extern cfe48d d018e8 teacher
print version debug_pointer_extern cfe48d d018e8 student
print version debug_pointer_extern cfe48d d018e8 car
