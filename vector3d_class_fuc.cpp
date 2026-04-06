/**
 * 按照题目要求实现三维向量类、成员函数、运算符重载。
 */
#include<iostream>
class Vector3d{
    public:
        double x,y,z;

        Vector3d():x(0.0),y(0.0),z(0.0){}    //1.默认构造函数

        Vector3d(double m_x ,double m_y ,double m_z):x(m_x),y(m_y),z(m_z){}  //2.赋值构造函数

        Vector3d(const Vector3d &other):x(other.x),y(other.y),z(other.z){}   //3.拷贝构造函数
        
        Vector3d& operator= (const Vector3d &other){
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;

            return *this;
        }                        // 4.重载=成员操作符

        double operator[] (int index) const{
            if(index == 0) return x;
            if(index == 1) return y;
            if(index == 2) return z;

            return 0.0;
        }                         //5.重载[]常量成员操作符

        double& operator[] (int index){
            if(index == 0) return x;
            if(index == 1) return y;
            if(index == 2) return z;

            return x;//(越界处理)
        }                         //6.重载[]成员操作符

        Vector3d operator+ (const Vector3d &other)const{
            return Vector3d(this->x + other.x,this->y + other.y,this->z + other.z);
        }                         //7.重载+常量成员操作符

        Vector3d& operator+=(const Vector3d &other){
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;

            return *this;
        }                         //8.重载+=成员操作符

        Vector3d operator* (double scalar) const{
            return Vector3d(this->x * scalar,this->y * scalar,this->z * scalar);
        }                         //9.重载*常量成员操作符

        Vector3d& operator*= (double scalar){
            this->x *= scalar;
            this->y *= scalar;
            this->z *= scalar;

            return *this;
        }                         //10.重载*=成员操作符

        double operator*(const Vector3d& other) const{
            return this->x * other.x + this->y*other.y + this->z * other.z;
        }                          //11.重构*常量成员操作符

        Vector3d operator^ (const Vector3d &other)const{
            return Vector3d(this->y*other.z-this->z * other.y,this->z*other.x - this->x * other.z,this->x *other.y - this->y * other.x);
        }                          //12.重构^常量成员操作符

        friend std::ostream& operator<< (std::ostream& os,const Vector3d &vec);            //13.重载<<全局操作符

        friend std::istream& operator>> (std::istream& is,Vector3d &vec);                  //14.重载>>全局操作符

        bool operator< (const Vector3d &other)const{
            if(this->x < other.x){
                return true;
            }

            if(this->x > other.x){
                return false;
            }

            if(this->y < other.y){
                return true;
            }

            if(this->y > other.y){
                return false;
            }

            return this->z < other.z;

        }                           //15.重载<常量成员操作符

};

std::ostream& operator<< (std::ostream& os,const Vector3d &vec){
    os<<"("<<vec.x<<" "<<vec.y<<" "<<vec.z<<")";
    return os;
}

std::istream& operator>> (std::istream& is,Vector3d &vec){
    char leftparen,rightparen;

    is>>leftparen>>vec.x>>vec.y>>vec.z>>rightparen;

    return is;
}