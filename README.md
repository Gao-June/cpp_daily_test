# 记录一些 写过的 cpp 代码

## 《C++面向对象高级编程代码资源-侯捷》
    里面放的是该视屏课提供的源代码

## day_11_17
>**ForOne.cpp**  
    “hello_world”测试代码 

## day_11_25
>### 01_primer_test1
>>**main.cpp** 
    练习使用 cosnt *, *const 

## day_11_26
>### 01_head_fild 
>>**main.cpp**  
    练习使用头文件
>>**funsum.h** 
    对应的头文件
>### 02_vector
>>**main.cpp**  
    简单小测试 string、sizeof()
>### 03_const_cast
>>**main.cpp**  
    const_cast<> 使用
>### 04_overriad
>>**main.cpp** 
    练习使用 重载 重写 覆盖
>### 05_func_point
>>**main.cpp** 
    练习使用 函数指针

## day_11_28
>### 01_class
>>**main.cpp** 
    写个class模板，以后就复制这一个
>### 02_class
>>**main.cpp** 
    默认构造函数、 this->
>### 03_const
>>**main.cpp** 
    练习使用 int const *p  和 int * const p
>### 04_func_const
>>**main.cpp**  
    成员函数后面加 const，表示常量函数
    const用在成员函数后 主要是针对类的const 对象
    const对象只能调用const成员函数。
    const对象的值不能被修改，在const成员函数中修改const对象数据成员的值是语法错误
    在const函数中调用非const成员函数是语法错误
>### 05_constructor_func
>>**main.cpp** 
    默认构造函数
>### 06_vector_capacity
>>**main.cpp** 
    练习使用 vector capacity()

## day_12_02
>### 01_lambda
>>**main.cpp** 
    写 lambda 函数

## day_12_03
>### 01_include
>>**main.cpp** 
    练习使用头文件  
>>**sum.h** 
    对应的头文件

>### 02_class_private
>>**main.cpp**  
    cpp 的 class 尽量将数据设为 private，不让外界看到；
    如果需要访问的话，可以再写函数 去访问数据。

>### 03_constructor
>>**main.cpp**  
    构造函数 可以有多种写法， 可以重载。
    但是注意，重载的前提是参数不一样
>### 04_func_const
>>**main.cpp**  
    func const
>### 05 return by reference
>>**main.cpp**  
    func const
>### 06 write complex
>>**main.cpp**  
    函数主题，尝试写一个 complex 类，包括一些 operator  
>>**complex.h**  
    头文件
>### 07 深拷贝，浅拷贝  
>>**main.cpp**  
    深拷贝，浅拷贝
## day_12_04
>### 01 static_cast
>>**main.cpp**  
    练习使用 static_cast  
>>**other_test_static_cast.cpp**  
    主要研究 static_cast 里面关于类的转换
>### 02 static  
>>**main.cpp**  
    练习一下static的写法  
    刚才上传的时候中文乱码了，改成 GB 2312再试试看
## day_12_07
>### 01 virtual func  
>>**main.cpp**  
    练习 基类写虚函数、纯虚函数；  
    派生类调用基类的函数、虚函数，改写基类的虚函数、纯虚函数
>### 02 转换函数  
>>**main.cpp**  
    转换函数 conversion func  
    写一个分数形式的转换函数  
    x = a/b  
>### 03 转换函数 + operator  
>>**main.cpp**  
    转换函数 conversion func  
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+  
    同时将 x 定义为 Base 类型  

    编译器报错 ambiguous，因为编译器不知道生成转化函数，还是 operator+ ,解决方法在 04章节  
>### 04 转换函数+operator+explict  
>>**main.cpp**  
    转换函数 conversion func + operator + explicit  
    
    相对于上一个转换函数（02_转换函数） 这里再引入 operator+  
    引入 explicit 是为了禁止编译器自动做隐式转换（在 ctor 处）  
    同时将 x 定义为 double 类型  
>### 05 练习operator
>>**main.cpp**  
    再练习一下 operator 的使用方法  github没显示中文注释  

## day_12_08
>### 01 c++版本测试
>>**main.cpp**  
    该指令可以测试自己编译器支持的cpp版本

>### 02 基类指向派生类
>>**main.cpp**  
    写一个多态，让基类指针指向派生类;  

    1- 当基类指针向调用派生类的 函数时，可以直接调用。  
    2-  ……想调用自己的 函数时，需要加作 用域运算符 ::  
    3- 注意，基类所调用的函数只能是：自己在基类里的、派生类重写的虚函数、派生类的纯虚函数；派生类的普通函数无法调用。  

>### 03 普通func后面能加 const 吗
>>**main.cpp**  
    普通函数后面能加 const 吗？  
    不能！ 只有 成员函数 才可以  
    【注】成员函数后加 const 的目的是为了 禁止对class里成员变量的更改。  

>### 04 size_t
>>**main.cpp**  
    size_t 是无符号 int 如果给 size_t赋值一个负数会怎样？


## day_12_09
>### 01 final关键字  
>> **main.cpp**  
    final:不希望某个类被继承（自己的类是最后的继承者）、或不希望某个虚函数被重写。  
    override:它指定了子类的这个虚函数是重写父类的，名字（或参数）如果不小心打错了，编译器不会编译通过。（做了安全检查）。  

>### 02 lambda
>> **main.cpp**  
    lambda 示例  
    1- 简单小示例  
    2- sort() 第三个参数，让 vertor 逆序排序  

>### 03 vector、unordered_map扩容
>> **main.cpp**  
    讨论 vector、unordered_map扩容

## day_12_10  
>### 01 calss 步骤 
    问题导入：
        1- 函数返回值是传值的时候发生几次对象析构，几次拷贝？
        2- 函数的形参是值传递的时候发生几次对象构造？

### 02 移动构造函数  
    学习一下 移动构造函数