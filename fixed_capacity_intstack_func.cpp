#include<iostream>

class FixedCapacityIntStack{
    private :
        const unsigned int m_capacity;
        unsigned int length;
        int* buffer;

    public :
        FixedCapacityIntStack(unsigned int capi):m_capacity(capi),length(0),buffer(nullptr){
            if (capi > 0){
                buffer = new int [capi];
            }else{
                buffer = nullptr;
            }
        }                 //1.指定容量的构造函数

        ~FixedCapacityIntStack(){
            if(buffer != nullptr){
                delete[] buffer;

                buffer = nullptr;
            }
        }                 //2.析构函数

        unsigned int capacity()const{
            return m_capacity;
        }                 //3.查询容量的常量成员函数

        unsigned int size() const{
            return length;
        }                  //4.查询长度

        bool empty() const{
            return length == 0;
        }                  //5.判断栈空

        bool full() const{
            return length == m_capacity;
        }                   //6.判断栈满


//以上为查询功能

        void push(int value){
            buffer[length] = value;
            length++;
        }                     //7.压栈存值
        
        void pop(){
            length --;
        }                      //8.弹栈出值

        int top() const{
            return buffer[length - 1];
        }                    //9.获取栈顶元素

        FixedCapacityIntStack(const FixedCapacityIntStack& other):m_capacity(other.m_capacity),length(other.length),buffer(nullptr){
            if(m_capacity > 0){
                buffer = new int[m_capacity];
            }

            if(other.buffer != nullptr){
                for(unsigned int i = 0;i<length;++i){ /*++i 是在循环体执行完之后才运行的*/
                buffer[i] = other.buffer[i];
                }   
            }
                         //10.拷贝构造函数
        }
};