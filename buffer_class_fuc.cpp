// 按照题目要求定义类和成员函数。
#include<cstdint>
#include<utility>    //提供std::swap函数
#include<algorithm>  //std::copy 要用

class Buffer{         //缓冲区
    private:
        uint64_t capacity;
        char* memoryBlock;

    public:
        Buffer():capacity(0),memoryBlock(nullptr){}
                       //1.默认构造函数
        Buffer(uint64_t capa):capacity(capa),memoryBlock(nullptr){
            if(capacity > 0){
                memoryBlock = new char[capacity]();
            }
        }                //2.赋值构造函数

        ~Buffer(){
            delete[] memoryBlock;
        }                // 7.析构函数，释放分配的内存块

        uint64_t size() const {
            return capacity;
        }                //3.获取容量

        char* addr(){
            return memoryBlock;
        }                //4.获取缓冲区地址的成员函数

        const char* addr() const{
            return memoryBlock;
        }                //5.获取缓冲区地址的常量成员函数

        void swap(Buffer& other){
            std::swap(this->memoryBlock,other.memoryBlock);
            std::swap(this->capacity,other.capacity);
        }                //6.交换成员函数swap

        Buffer(const Buffer& other){
            this->capacity = other.capacity;

            if (this->capacity == 0){
                this->memoryBlock = nullptr;
                return;
            }

            this->memoryBlock = new char[this->capacity];

            std::copy(other.memoryBlock,other.memoryBlock + this->capacity,this->memoryBlock);
        }                //8.拷贝构造函数

        /*Buffer& operator = (const Buffer& other){
            if(this == &other) return *this;

            delete[] memoryBlock;

            capacity = other.capacity;
            memoryBlock = new char[capacity];
            std::copy(other.memoryBlock,other.memoryBlock + capacity,memoryBlock);

            return *this;
        }               //9.拷贝赋值运算符 */
        
        Buffer& operator= (const Buffer& other){
            Buffer temp(other);

            this->swap(temp);

            return *this;
        }               //9.拷贝赋值函数

        Buffer (Buffer&& other){
            capacity = other.capacity;
            memoryBlock = other.memoryBlock;

            other.capacity = 0;
            other.memoryBlock = nullptr;

        }               //10.移动构造函数

        Buffer& operator=(Buffer&& other){
            if(this != &other){
                Buffer temp;

                std::swap(memoryBlock ,temp.memoryBlock);
                std::swap(capacity,temp.capacity);

                std::swap(memoryBlock,other.memoryBlock);
                std::swap(capacity,other.capacity);
            }

            return *this;
        }                   //11.移动赋值运算符

};