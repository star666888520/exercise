/**
 * 按照题目要求实现三维矩阵类、成员函数、运算符重载。
 * 
 * 评测环境将提供符合《三维向量类》题目的实现，无需复制。
 */
#include <stdexcept>  //抛出错误
#include<iostream>    //方便输入输出
class Matrix3d{
    private:
        Vector3d rows[3];

    public:
        Matrix3d():rows{Vector3d(),Vector3d(),Vector3d()}{}   //1.默认构造函数

        Matrix3d(const double *data){
            for(int i = 0;i < 3;i++){
                rows[i] = Vector3d(data[i*3],data[i*3+1],data[i*3+2]);
            }                       //2.赋值构造函数
        }

        Matrix3d(const Matrix3d& other):rows{other.rows[0],other.rows[1],other.rows[2]}{}       //3.拷贝构造函数

        Matrix3d& operator= (const Matrix3d &other){
            if(this == &other){
                return *this;
            }

            for(int i = 0;i<3;++i){
                rows[i] = other.rows[i];
            }

            return *this;
        }                       //4.重载=成员操作符

        const Vector3d& operator[](int index) const{
            if(index < 0 || index >=3){
                throw std::out_of_range("Index out of range");
            }

            return rows[index];
        }                        //5.重载[]常量成员操作符

        Vector3d& operator[](int index) {
            if(index < 0 || index >=3){
                throw std::out_of_range("Index out of range");
            }

            return rows[index];
        }                           //6.重载[]成员操作符

        Matrix3d& operator +=(const Matrix3d& other){
            for(int i = 0;i<3;i++){
                this->rows[i] += other.rows[i];
            }

            return *this;
        }                        //7.重载+=成员操作符

        Matrix3d operator+ (const Matrix3d &other)const{
            Matrix3d result = *this;
            result += other;
            return result;      
        }                       //8.重载+常量成员运算符

        Matrix3d& operator *= (double scalar){
            for(int i = 0;i<3;i++){
                this->rows[i] *= scalar;
            }

            return *this;
        }                        //9.重载*=成员操作符

        Matrix3d operator*(double val)const{
            Matrix3d result = *this;
            result *= val;
            return result ;
        }                       //10.重载*常量成员运算符实现标量乘法

        Matrix3d operator *(const Matrix3d& other)const{
            Matrix3d result ;

            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    for(int k = 0;k < 3;k++){
                        result.rows[i][j] += this->rows[i][k] * other.rows[k][j];
                    }
                }
            }

            return result;
        }                       //11.重载*常量成员运算符实现矩阵乘法


        static Matrix3d identity(){
            Matrix3d mat;

            for (int i = 0;i<3;++i){
                mat.rows[i][i] = 1.0; 
            }

            return mat;
        }                     //12.获取单位矩阵的静态成员函数

        static Matrix3d scale(double sx,double sy,double sz){
            Matrix3d mat = identity();

            mat.rows[0][0] = sx;
            mat.rows[1][1] = sy;
            mat.rows[2][2] = sz;

            return mat;
        }                     //13.获取缩放变换矩阵的静态成员函数

        friend Vector3d operator* (const Matrix3d& mat,const Vector3d& vec);   //声明友元，给予访问权限
       
};

Vector3d operator*(const Matrix3d& mat,const Vector3d& vec){
    Vector3d result;

    result.x = mat.rows[0].x * vec.x + mat.rows[0].y*vec.y + mat.rows[0].z * vec.z;
    result.y = mat.rows[1].x * vec.x + mat.rows[1].y*vec.y + mat.rows[1].z * vec.z;
    result.z = mat.rows[2].x * vec.x + mat.rows[2].y*vec.y + mat.rows[2].z * vec.z;

    return result;
}                               //14.重载*全局操作符
