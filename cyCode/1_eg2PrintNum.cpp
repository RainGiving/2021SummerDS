#include <iostream>
using namespace std;
void PrintN_C(int N); //循环
void PrintN_R(int N); // 递归
int main()
{
    int N;
    cin >> N;
    PrintN_C(N);
    return 0;
}

void PrintN_C(int N)
{
    for (int i = 1; i < N + 1; i++)
        cout << i << endl;
    return;
}
void PrintN_R(int N)
{
    if (N != 1)
        PrintN_R(N - 1);
    cout << N << endl;
}