/**
 * ��Щ������Ȼ��Ҫ д�� non-member func������ʽ����ת����implicit type conversion��
 * ��Effective C++�� ����-24�������в�����������ת������Ϊ�˲��� Non-member func()
 * 
 * ������ дһ�� operator*�� Ȼ������佻����
 * ���ۣ�
 *  ���� member func() �У�д��Entity operator* ( const Entity& e) ����ɲ�����ʽת�������⣻
 *  ��д�� non-member func()ʱ��д��Entity operator* ( const Entity& e1, const Entity& e2 )
 *      ���������ʽת��
 * ��ע��
 *      ��д operator* ��ʱ��e1 * e2 return����һ�� ��ʱֵ�����Ժ���Ҫ return-by-value
 *      ���Լ�д��һ�� operator *=�� ���Է��ַ���ֵ��������˿��� return-by-reference
 */

#include <iostream>

class Entity{
public:
    // �ڹ��캯���и�����ʼֵ���������� * ����
    Entity( int x = 0, int y = 0) : _x(x), _y(y){
        std::cout << "ctor" << std::endl;
    }
    Entity( const Entity& e ) : _x(e._x), _y(e._y){
        std::cout << "copy ctor" << std::endl;
    }
    ~Entity( ){
        std::cout << "dtor" << std::endl;
    }

public:
    void Print( ) const{
        std::cout << "x: " << _x << " y: " << _y << std::endl;
    }

    // Entity operator* ( const Entity& e){
    //     this->_x *= e._x;
    //     this->_y *= e._y;
    //     return *this;
    // }

    // p.s �����棨operator*���������д�� *=�� �������� const Entity& operator*=(...)��
    // ���Եģ�
    const Entity& operator*= ( const Entity& e){
        this->_x *= e.Get_x();
        this->_y *= e.Get_y();
        return *this;
    }


    // ���� _x, _y �� private��������Ҫд func() �õ��ñ���
    int Get_x( ) const{
        return _x;
    }
    int Get_y( ) const {
        return _y;
    }

private:
    int _x, _y;
};

// д�� non-member func()
// p.s. ���ﲻ��д�� const Entity& operator*(...) ��Ϊ���ܶ�һ����ʱֵ���з����� reference
const Entity operator* ( const Entity& e1, const Entity& e2 ){
    return Entity( e1.Get_x() * e2.Get_x(), e1.Get_y() * e2.Get_y());
}


int main( ){
    std::cout << "test No.1" << std::endl;
    Entity e1(1, 2);
    Entity e2(3, 4);
    e1.Print();
    e2.Print();
    e1 = e1 * e2;
    e1.Print();

    std::cout << "test No.2" << std::endl;
    Entity e3(1, 2);
    Entity e4(1,2);
    e3 = e3 * 2;
    e3.Print();

    // Entity operator* ( const Entity& e) ʱ������ʽת��
    // д�� non-member funcʱ�������ʽת��
    e4 = 2 * e4;
    e4.Print();

    // ���� *=
    std::cout << "test No.3" << std::endl;
    Entity e5(1, 2);
    Entity e6(1, 2);
    e5 *= e6;
    e5.Print();

    return 0;
}