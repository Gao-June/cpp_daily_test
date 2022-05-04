/**
 * 用仿函数、lambda对set进行自定义排序
 * 
 * 仿函数：
 *  1 - 仿函数不是函数，它是个类；
 *  2 - 仿函数重载了()运算符，使得它的对你可以像函数那样子调用(代码的形式好像是在调用函数)。
 * 
 * 实现：
 *  我先按照教材里的仿函数写，然后替换成 lambda试试。
 *  有点难度，万能的百度哈哈
 */

#include <iostream>
#include <string>
#include <set>

class Student{
public:
    Student( std::string name, int age ) : _name(name), _age(age){}

public:
    std::string _name;
    int _age;
};

// 仿函数
class StuFunctor{
public:
    // p.s. 报错：error: static assertion failed: comparison object must be invocable as const
    // 设置函数为 const就行
    bool operator() (const Student& l, const Student& r) const{
        return (l._age > r._age);   // 年龄 由大到小
    }
};


int main( ){
    //std::set< Student, StuFunctor > set1;      // 也写上仿函数，根据仿函数进行排序

    // 接下来改上面仿函数为 lambda 试试
    // 报错，自己的水平暂时也不知道该怎么弄咯
    // 哈哈，我又会了
    auto cmp = []( const Student& l, const Student& r ) {return (l._age >= r._age);};
    // 由于 set 声明式需要指明 lambda类型， 所以我们必须使用 decltype，它会为一个lambda对象产出类型。
    // 注意，你也必须把 lambda对象传入给 set1的构造函数，否则set1会调用被传入的排序准则的default构造函数。
    // 而根据C++语言规则，lambda没有 default构造函数。
    std::set< Student, decltype(cmp)> set1(cmp);

    set1.insert( Student("张三", 32) );
    set1.insert( Student("李四", 44) );
    set1.insert( Student("王五", 21) );
    set1.insert( Student("赵八", 65) );

    for( auto it = set1.begin(); it != set1.end(); it ++ ){
        std::cout << (*it)._name << "  " << (*it)._age << std::endl;
    }

    return 0;
}