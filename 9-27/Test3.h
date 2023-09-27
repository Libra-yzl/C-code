#pragma once

//使用宏函数完成一个add函数
#define ADD(x,y) ((x)+(y))

//使用内联函数进行替换
inline int Add(int x, int y) { return x + y; }