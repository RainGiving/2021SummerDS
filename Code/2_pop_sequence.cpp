#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    while (k--)
    {
        vector<int> pool(n, 0);
        for (int i = 0; i < n; i++)
            cin >> pool[i]; //输入一行输出序列,存到数字池pool中

        stack<int> s;
        int pool_now = 0; //当前指向序列的索引
        int num = 1;
        bool flag = true;

        while (pool_now < n)
        {
            if (s.empty())     //当前栈为空
                s.push(num++); //按顺序放一个数入栈
            else               //栈不空
            {
                //如果栈顶元素和当前数字池指向的数字相同
                if (s.top() == pool[pool_now])
                {
                    s.pop();    //直接出栈即可
                    pool_now++; //指向数字池下一个元素
                }
                //栈顶元素较小
                else if (s.top() < pool[pool_now])
                {
                    //检查是否满栈,若满了则不可能出栈为pool_now指向的数，该序列不可能是出栈序列
                    if (s.size() == m)
                    {
                        flag = false;
                        break;
                    }
                    else //若没满，继续入栈
                        s.push(num++);
                }
                //栈顶元素大于当前pool_now指向的数字，该序列不可能是出栈序列
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}