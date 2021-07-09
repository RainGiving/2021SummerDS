#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;

clock_t start, stop;
double duration; //记录被测函数运行时间，以秒为单位
int main()
{
    //不在测试范围的准备工作
    start = clock();
    //这里写被测函数
    //如果被测函数太快，根本不到一个tick，建议重复运行！
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    //不在测试范围的后继工作
    return 0;
}