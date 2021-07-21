#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];

    //在线处理算法
    int thisSum = 0, maxSum = 0;
    // 这几个变量用来存放thisSum和maxSum对应的首尾元素的索引
    int thisHead = 0, thisTail = 0, maxHead = 0, maxTail = 0;
    for (int i = 0; i < k; i++)
    {
        thisSum += a[i];
        thisTail = i; //加上a[i]后thisSum对应的尾元素自然是a[i]
        if (thisSum < 0)
        {
            //thisSum置零将前面的元素全部抛弃，将其首尾元素置为后面第一个元素
            thisSum = 0;
            thisHead = i + 1;
            thisTail = i + 1;
        }
        else if (thisSum > maxSum)
        {
            //将thisSum对应的子串接纳为最大子串，最大子串对应的首尾元素也要同时更改
            maxSum = thisSum;
            maxHead = thisHead;
            maxTail = thisTail;
        }
    }

    if (maxSum == 0 && maxHead == 0 && maxTail == 0 && a[0] <= 0) //针对全为负数或0的情况
    {
        int flag = -1; //记录第一个0的位置，如果没有0就保持-1
        for (int i = 0; i < k; i++)
            if (a[i] == 0)
            {
                flag = i;
                break;
            }
        if (flag == -1) //全为负数，将maxTail置为整个数组尾部索引
            maxTail = k - 1;
        else //存在0，将第一个0的位置设为maxHead与maxTail
        {
            maxHead = flag;
            maxTail = flag;
        }
    }

    cout << maxSum << ' ' << a[maxHead] << ' ' << a[maxTail] << endl;
    return 0;
}