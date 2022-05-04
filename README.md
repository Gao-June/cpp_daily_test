# 记录一些 写过的 cpp 代码

## 《C++面向对象高级编程代码资源-侯捷》
    里面放的是该视屏课提供的源代码

## day_11_17
    “hello_world” 测试代码 

## day_11_25
>### 01_primer_test1
    练习使用 cosnt *, *const 

## day_11_26
>### 01_head_fild 
>>**main.cpp**  
    练习使用头文件
>>**funsum.h** 
    对应的头文件
>### 02_vector
    简单小测试 string、sizeof()
>### 03_const_cast
    const_cast<> 使用
>### 04_overriad
    练习使用 重载 重写 覆盖
>### 05_func_point
    练习使用 函数指针

## day_11_28
>### 01_class
    写个class模板，以后就复制这一个
>### 02_class
    默认构造函数、 this->
>### 03_const
    练习使用 int const *p  和 int * const p
>### 04_func_const
    成员函数后面加 const，表示常量函数
    const用在成员函数后 主要是针对类的const 对象
    const对象只能调用const成员函数。
    const对象的值不能被修改，在const成员函数中修改const对象数据成员的值是语法错误
    在const函数中调用非const成员函数是语法错误
>### 05_constructor_func
    默认构造函数
>### 06_vector_capacity
    练习使用 vector capacity()

## day_12_02
>### 01_lambda
    写 lambda 函数

## day_12_03
>### 01_include
>>**main.cpp** 
    练习使用头文件  
>>**sum.h** 
    对应的头文件

>### 02_class_private 
    cpp 的 class 尽量将数据设为 private，不让外界看到；
    如果需要访问的话，可以再写函数 去访问数据。

>### 03_constructor
    构造函数 可以有多种写法， 可以重载。
    但是注意，重载的前提是参数不一样
>### 04_func_const
    func const
>### 05 return by reference 
    func const
>### 06 write complex
>>**main.cpp**  
    函数主题，尝试写一个 complex 类，包括一些 operator  
>>**complex.h**  
    头文件
>### 07 深拷贝，浅拷贝  
    深拷贝，浅拷贝


## day_12_04
>### 01 static_cast
    练习使用 static_cast   
    主要研究 static_cast 里面关于类的转换
>### 02 static   
    练习一下static的写法  
    刚才上传的时候中文乱码了，改成 GB 2312再试试看


## day_12_07
>### 01 virtual func  
    练习 基类写虚函数、纯虚函数；  
    派生类调用基类的函数、虚函数，改写基类的虚函数、纯虚函数
>### 02 转换函数  
    转换函数 conversion func  
    写一个分数形式的转换函数  
    x = a/b  
>### 03 转换函数 + operator  
    转换函数 conversion func  
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+  
    同时将 x 定义为 Base 类型  

    编译器报错 ambiguous，因为编译器不知道生成转化函数，还是 operator+ ,解决方法在 04章节  
>### 04 转换函数+operator+explict  
    转换函数 conversion func + operator + explicit  
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+  
    引入 explicit 是为了禁止编译器自动做隐式转换（在 ctor 处）  
    同时将 x 定义为 double 类型  
>### 05 练习operator 
    再练习一下 operator 的使用方法  github没显示中文注释  

## day_12_08
>### 01 c++版本测试 
    该指令可以测试自己编译器支持的cpp版本

>### 02 基类指向派生类 
    写一个多态，让基类指针指向派生类;  

    1- 当基类指针向调用派生类的 函数时，可以直接调用。  
    2-  ……想调用自己的 函数时，需要加作 用域运算符 ::  
    3- 注意，基类所调用的函数只能是：自己在基类里的、派生类重写的虚函数、派生类的纯虚函数；派生类的普通函数无法调用。  

>### 03 普通func后面能加 const 吗
    普通函数后面能加 const 吗？  
    不能！ 只有 成员函数 才可以  
    【注】成员函数后加 const 的目的是为了 禁止对class里成员变量的更改。  

>### 04 size_t 
    size_t 是无符号 int 如果给 size_t赋值一个负数会怎样？


## day_12_09
>### 01 final关键字   
    final:不希望某个类被继承（自己的类是最后的继承者）、或不希望某个虚函数被重写。  
    override:它指定了子类的这个虚函数是重写父类的，名字（或参数）如果不小心打错了，编译器不会编译通过。（做了安全检查）。  

>### 02 lambda
    lambda 示例  
    1- 简单小示例  
    2- sort() 第三个参数，让 vertor 逆序排序  

>### 03 vector、unordered_map扩容 
    讨论 vector、unordered_map扩容

## day_12_10  
>### 01 calss 步骤 
    问题导入：
        1- 函数返回值是传值的时候发生几次对象析构，几次拷贝？
        2- 函数的形参是值传递的时候发生几次对象构造？

>### 02 移动构造函数  
    学习一下 移动构造函数（代码有bug，不知道怎么办 =.=)


## day_12_11
>### 01 tuple 元组  
    练习 tuple 元组

## day_12_13
>### 01 typedef  
    在 golang 中，自定义类型不会继承基础类型的其它信息;  
    测试一下 cpp 可不可以   => 可以

## day_12_14  
>### 01 count_if  
    研究 count_if 的使用
    标准库里的count_if可以统计容器中满足特定条件的元素的个数。  
    另，本代码尝试了使用 lambda 实现

## day_12_15
>### 01 lambda + sort  
    用 Lambda 实现 sort 逆序  

>### 02 list max_size()  
    使用 list max_size( ) 查看 list 的最大容量  357913941

## day_12_16  
>### 01 test  
    随便写的测试程序

## day_12_18
>### 都是随便写的测试 git - vs code - github 能否连接        

## day_12_23  
>### 写一个仿函数operator 来实现之前得 Lambda功能（逆序排序）


## day_2022_04_02
>### goto 测试
>### 生成伪随机数
>### 隐式转换问题

## day_2022_04_04
>### 静态成员函数 
>### 操作符重载 
>### const 函数
>### operator<、函数模板

## day_2022_04_05
>### 练习使用 public/protected/private 三种继承

## day_2022_04_06
>### 函数写在其它 cpp里，而不是之前的 .h
>### 探究 #define
>### 在创建 float double的时候，会显示都是 double变量

## day_2022_04_07
>### 随便写了写
## day_2022_04_07
>### 检验 pc 电脑是大端还是小端

## day_2022_04_14
>###  enum 使用

## day_2022_04_18
>###  char*, char[]的一些比较
>###  class 的成员初始化列表

## day_2022_04_19
>###  隐式转换
>###  再练习一下 operator 操作
>###  简单练习了下 master_ptr  

## day_2022_04_20
>###  手写 string
>###  operator ->
    学习使用 operator ->
    const指针 只能调用 const func
###  -> 获取偏移量
    long long offset_x =  (long long )&( (Vector3*)nullptr)->x;
### 代码优化： 探究 push_back vs emplace_back   
### 跨文件调用库
### 函数模板
### template 另一种神奇的使用方法


## day_2022_04_21
>### 使用 using
>###  函数指针
    给出了函数指针的几种不同的写法
    常规、auto、typedef
>###  函数指针
    函数指针做参数进行调用
    在方法-2 中给出了 lambda 代替函数指针的实例
    所有函数指针 都可以用 lambda 代替
## day_2022_04_23
>### 线程
>### 交替打印 A B 线程
>### 检验程序运行时间 
>### 对 03 中的程序运行时间进行优化；
    写一个 class Timer
    构造函数初始化时间，析构函数求结束时间（利用了程序运行完调用析构函数的特点）
>### new 二维数组

## day_2022_04_24
>### 帮小吴做题

## day_2022_04_25
>### 虚析构函数

## day_2022_04_26
>### C++ 生成到 C++17
    配置完后要重启 vs code才行
>### 更新了一个测时的 项目 Instrumentor Timer

>###  这里使用了C++17 的特性 string_view
通过对 operator new() 的测试，能节省 一半的内存开销
>###  探究左值引用 与 右值引用

## day_2022_04_27
>### 探究 函数在传参的时候的调用顺序
    结论，先调用后面的参数，再调用前面的

>###   move构造函数 探究右值引用
这两个例子写的很好！
问题描述：
       class 在拷贝过程中可能调用 默认构造函数和拷贝构造函数
       这样可能（由2次拷贝）导致空间资源浪费
解决方法：用 移动语义 来解决。
       在此示例中，只需写一个 move 构造函数，这和 copy构造函数相似，
       除了它接收的是一个右值（临时值）之外
代码展示：
       main1.cpp 复现 2 次 copy过程
       main2.cpp 使用 move 构造函数对照（把 copy构造函数注释掉）
       
>### assignment move()
std::move 是一个由标准库提供的实用函数
在编译时，它会找出输入的是什么类型。
另外补充了 assignment move版

## day_2022_05_02
>### 探究 size_t的使用
>### 《Effective C++》 01_size_t
>### 《Effective C++》 02_隐式转换 explicit

## day_2022_05_03
>### 《Effective C++》 03_func()后接 const
>### 《Effective C++》 04_不允许类被拷贝、赋值
>### 《Effective C++》 05_operator=
>### operator +=
>### copy ctor 里参数写 const，能调用非const class吗？
>### 简单调试

## day_2022_05_03
>### 《Effective C++》 06_operator =
>### 《Effective C++》 07_以 pass-by-reference-to-const 替换 pass-by-value
>### 《Effective C++》 08_探究 return-by-reference 和 return by object的区别
>### 《Effective C++》 09_有些场景仍然需要 写成 non-member func进行隐式类型转换
>### 学习 assert 的用法

