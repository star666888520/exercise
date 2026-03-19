// 按照题目要求定义类和成员函数。
#include <iostream>
#include <cmath>

class Point{
    private:
        double m_x,m_y;   //0.

    public:
        Point():m_x(0.0),m_y(0.0){}  //1.默认构造函数

        Point(double tx,double
            ty) :m_x(tx),m_y(ty){}  //2.赋值构造函数

        double x() const{
            return m_x;
        }       
        
        double y() const{
            return m_y;
        }       //3.获取直角坐标，常量成员函数

        void x(double nx){
            m_x = nx;
        }

        void y(double ny){
            m_y = ny;
        }        //4.设置直角坐标分量

        void set(double sx,double sy){
            m_x = sx;
            m_y = sy;
        }                    //5.设置直角坐标

        double polar_radius()const {
            return std::sqrt(m_x*m_x + m_y *m_y);
        }                  //6.获取极径，常量成员函数

        double polar_angle()const{
            return std::atan2(m_y,m_x);
        }                 //7.获取极坐标极角

        double distance(const Point &other) const{
            double dx = m_x - other.m_x;
            double dy = m_y - other.m_y;
            return std::sqrt(dx*dx + dy * dy);
        }                  //8.获取两点间的距离

        bool is_near(const Point &other,double eps = 1e-8)const{
            return  distance(other)<=eps;
        }                  //9.判断两点邻近

};