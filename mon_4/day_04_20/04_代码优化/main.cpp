/** �����Ż��� ̽�� push_back vs emplace_back
 * 
 * ����Ϊʲô�м��༸�� copy��    ��Ϊ vector����
 * 
 * v3.emplace_back( 1, 2, 3 ); ������
 * �����ǰ reserve() ��������������ô push_back() �� emplace_back()һ����
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
   // ������ 3 ��Ĭ�Ϲ��캯����6�ο������캯�� 
    std::cout << "No.1" << std::endl;
    std::vector<Entity> v1;
    v1.push_back( {1, 2, 3} );
    v1.push_back( {4, 5, 6} );
    v1.push_back( {7, 8, 9} );

   // ������ 3 ��Ĭ�Ϲ��캯����6�ο������캯�� 
    std::cout << "No.2" << std::endl;
    std::vector<Entity> v2;
    v2.push_back( Entity(1, 2, 3) );
    v2.push_back( Entity(4, 5, 6) );
    v2.push_back( Entity(7, 8, 9) );

// ���������
   // ������ 3 ��Ĭ�Ϲ��캯����3�ο������캯�� 
    std::cout << "No.3" << std::endl;
    std::vector<Entity> v3;
    v3.emplace_back( 1, 2, 3 );
    v3.emplace_back( 4, 5, 6 );
    v3.emplace_back( 7, 8, 9 );


   // ������ 3 ��Ĭ�Ϲ��캯����6�ο������캯�� 
    std::cout << "No.4" << std::endl;
    std::vector<Entity> v4;
    v4.emplace_back( Entity(1, 2, 3) );
    v4.emplace_back( Entity(4, 5, 6) );
    v4.emplace_back( Entity(7, 8, 9) );

//����Ϊʲô�м��༸�� copy��    ��Ϊ vector����
//�����ǰ reserve() ��������������ô push_back() �� emplace_back()һ����
    // ������ 3 ��Ĭ�Ϲ��캯����3�ο������캯�� 
    std::cout << "No.5" << std::endl;
    std::vector<Entity> v5;
    v5.reserve(3);
    v5.push_back( Entity(1, 2, 3) );
    v5.push_back( Entity(4, 5, 6) );
    v5.push_back( Entity(7, 8, 9) );

    // ������ 3 ��Ĭ�Ϲ��캯����3�ο������캯�� 
    std::cout << "No.6" << std::endl;
    std::vector<Entity> v6;
    v6.reserve(3);
    v6.emplace_back( Entity(1, 2, 3) );
    v6.emplace_back( Entity(4, 5, 6) );
    v6.emplace_back( Entity(7, 8, 9) ); 


    return 0;
}