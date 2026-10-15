// coordin.h -- structure templates and function prototypes
// structure templates
#ifndef COORDIN_H_//使用ifndef防止重复引用(重复引用会导致结构体和函数原型被重复声明,而重复声明会导致问题)
#define COORDIN_H_//ifndef则保证引用一定只触发一次定义

struct polar
{
    double distance;    // distance from origin
    double angle;       // direction from origin
};

struct rect
{
    double x;           // horizontal distance from origin
    double y;           // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif//ifndef结束语句
//链接多个文件时注意使用同一编译器,否则容易导致链接错误