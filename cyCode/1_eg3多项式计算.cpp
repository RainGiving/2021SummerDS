#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//暴力的算法
double f1(int n, double a[], double x)
{
    double p = a[0];
    for (int i = 1; i <= n; i++)
        p += a[i] * pow(x, i);
    return p;
}

//秦九韶算法
double f2(int n, double a[], double x)
{
    double p = a[n];
    for (int i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}

#define MAXN 10
#define MAXK 1e9

clock_t start, stop;
double duration1, duration2; //记录被测函数运行时间，以秒为单位
int main()
{
    double a[MAXN];
    for (int i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }
    //不在测试范围的准备工作
    start = clock();
    //这里写被测函数
    //如果被测函数太快，根本不到一个tick，建议重复运行！
    for (int i = 0; i < MAXK; i++)
        f1(MAXN - 1, a, 1.1);
    stop = clock();
    duration1 = (double)(stop - start) / CLK_TCK;
    //不在测试范围的后继工作
    cout << "duration1 is " << duration1 << "s" << endl;

    //不在测试范围的准备工作
    start = clock();
    //这里写被测函数
    //如果被测函数太快，根本不到一个tick，建议重复运行！
    for (int i = 0; i < MAXK; i++)
        f2(MAXN - 1, a, 1.1);
    stop = clock();
    duration2 = (double)(stop - start) / CLK_TCK;
    //不在测试范围的后继工作
    cout << "duration2 is " << duration2 << "s" << endl;
    return 0;
}