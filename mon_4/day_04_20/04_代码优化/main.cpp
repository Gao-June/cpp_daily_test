/** 代码优化： 探究 push_back vs emplace_back
 * 
 * 解释为什么中间会多几次 copy：    因为 vector扩容
 * 
 * v3.emplace_back( 1, 2, 3 ); 是最快的
 * 如果提前 reserve() 扩好了容量，那么 push_back() 和 emplace_back()一样快
*/ 

#include <iostream>
#include <vector>

struct Entity
{
    float _x, _y, _z;

    Entity( float x, float y, float z ) : _x(x), _y(y), _z(z) {
        std::cout << "construct!" << std::endl;
    }

    // copy construct
    Entity( const Entity& entity ) : _x(entity._x), _y(entity._y), _z(entity._z)
    {
        std::cout << "copy!" << std::endl;
    }

};

int main()
{
   // 调用了 3 次默认构造函数，6次拷贝构造函数 
    std::cout << "No.1" << std::endl;
    std::vector<Entity> v1;
    v1.push_back( {1, 2, 3} );
    v1.push_back( {4, 5, 6} );
    v1.push_back( {7, 8, 9} );

   // 调用了 3 次默认构造函数，6次拷贝构造函数 
    std::cout << "No.2" << std::endl;
    std::vector<Entity> v2;
    v2.push_back( Entity(1, 2, 3) );
    v2.push_back( Entity(4, 5, 6) );
    v2.push_back( Entity(7, 8, 9) );

// 这个是最快的
   // 调用了 3 次默认构造函数，3次拷贝构造函数 
    std::cout << "No.3" << std::endl;
    std::vector<Entity> v3;
    v3.emplace_back( 1, 2, 3 );
    v3.emplace_back( 4, 5, 6 );
    v3.emplace_back( 7, 8, 9 );


   // 调用了 3 次默认构造函数，6次拷贝构造函数 
    std::cout << "No.4" << std::endl;
    std::vector<Entity> v4;
    v4.emplace_back( Entity(1, 2, 3) );
    v4.emplace_back( Entity(4, 5, 6) );
    v4.emplace_back( Entity(7, 8, 9) );

//解释为什么中间会多几次 copy：    因为 vector扩容
//如果提前 reserve() 扩好了容量，那么 push_back() 和 emplace_back()一样快
    // 调用了 3 次默认构造函数，3次拷贝构造函数 
    std::cout << "No.5" << std::endl;
    std::vector<Entity> v5;
    v5.reserve(3);
    v5.push_back( Entity(1, 2, 3) );
    v5.push_back( Entity(4, 5, 6) );
    v5.push_back( Entity(7, 8, 9) );

    // 调用了 3 次默认构造函数，3次拷贝构造函数 
    std::cout << "No.6" << std::endl;
    std::vector<Entity> v6;
    v6.reserve(3);
    v6.emplace_back( Entity(1, 2, 3) );
    v6.emplace_back( Entity(4, 5, 6) );
    v6.emplace_back( Entity(7, 8, 9) ); 


    return 0;
}