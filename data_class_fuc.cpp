// 按照题目要求定义类和成员函数。
#include<cstdint>  /*提供固定宽度的整数类型定义*/
#include<ctime>    /*提供日期和时间处理功能*/
#include<iostream> /*提供标准输入输出流对象*/
#include<iomanip>  /*提供输入输出流的格式控制（输出函数，操纵符）*/

class Date{
    private:
        unsigned int date;

    public:
    Date(){
        std::time_t now = std::time(nullptr);
        std::tm* local_tm = std::localtime(&now);

        unsigned int year = local_tm->tm_year + 1900;
        unsigned int month = local_tm->tm_mon + 1;
        unsigned int day = local_tm->tm_mday;

        date = year * 10000+month*100+day;
    }                          //1.默认构造函数（默认初始化为当前日期）

    Date(int year ,int month ,int day){
        if(year < 1800||year > 9999){
            *this = Date();
            return;
        }

        if(month < 1||month>12){
            *this = Date();
            return ;
        }

        int maxDay;
        maxDay = getMaxDay(year,month);

        if(day < 1||day >maxDay){
            *this = Date();
            return;
        }

        date = static_cast<unsigned int>(year * 10000 + month * 100 + day);
    }                             //2.赋值构造函数

    //查询函数
    int year ()const{
        return date / 10000;
    }            //3.查询年份

    int month ()const{
        return (date % 10000)/100; //(date/100)%100
    }            //4.查询月份

    int day ()const{
        return date % 100;
    }           //5.查询日期

    bool is_leap_year()const {
        int y = year();
        return (y%400 == 0) || (y%4 == 0&&y%100!=0);
    }           //6.查询是否闰年(注意看用什么写。变量有没有)

    //输出函数
    void print (std::ostream& os)const{
        os << std::setfill('0')
           << std::setw(4) << year()<<"-"
           << std::setw(2) << month()<<"-"
           << std::setw(2) <<day();
    }            //7.输出日期

    static int check(int y,int m ,int d){
        if (y<1800 || y>9999){
            return -1;
        }

        if(m > 12||m<1){
            return -2;
        }

        int maxDay;
        maxDay = getMaxDay(y,m);

        if (d<1||d>maxDay){
            return -3;
        }

        return 0;
    }                  //8.验证日期是否正确

    int set(int y,int m,int d){
        int result = Date::check(y,m,d);

        if(result != 0){
            return result;
        }

        this->date = static_cast<unsigned int>(y*10000+m*100+d);

        return 0;

    }                 //9.设置日期

    private:
    static int getMaxDay(int year ,int month){
        int maxDay;
        if(month == 2){
            bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100!=0);
            maxDay = isLeap ? 29 :28;
        }else if (month == 4 || month == 6||month == 9||month == 11){
            maxDay = 30 ;
        }else {
            maxDay = 31;
        }              

        return maxDay;       //确定一月最大天数（注意闰年）
    }
    
};