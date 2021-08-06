#include <iostream>
using namespace std;
const int maxn = 100010;
struct node
{
    int data;
    int next;
} List[maxn];
int head, N, K; //节点数N，翻转前K个节点

void Input()
{
    cin >> head >> N >> K;
    int tmp_index, tmp_data, tmp_next;
    int n = N;
    while (n--)
    {
        cin >> tmp_index >> tmp_data >> tmp_next;
        List[tmp_index].data = tmp_data;
        List[tmp_index].next = tmp_next;
    }
}

void ReverseList()
{
    if (K == 1) // K=1时不需要进行任何操作即可
        return;
    //查找输入的链表有多少节点
    int i = head, cnt = 1;
    while (List[i].next != -1)
    {
        cnt++;
        i = List[i].next;
    } //最后cnt的值就是这个链表的节点个数

    //先完成第K个节点和头节点的交换
    if (1 < K)
    {
        int beforeK = head;
        int step = K - 2; //从head开始向前走K-1步到第K个节点，走K-2步到第K-1个节点
        //首先找到第K个节点的前一个节点的索引
        while (step--)
            beforeK = List[beforeK].next;

        int K_index = List[beforeK].next; //当前K的索引
        int head_next = List[head].next;  //head的下一个节点的索引
        int K_next = List[K_index].next;  //第K个节点的下一个节点的索引

        if (beforeK == head)
        {
            List[K_index].next = head; //1
            List[head].next = K_next;  //2
        }
        else
        {
            List[K_index].next = head_next; //K的next设为head的next
            List[beforeK].next = head;      //K的前一个节点的next设为head
            List[head].next = K_next;       //head的next设为原K的next
        }
        head = K_index; //头节点的索引已经变为第K个节点的索引
    }

    for (int i = 2, j = K - 1; i < j; i++, j--)
    {
        int fstep = i - 2, rstep = j - 2, before_index1 = head, before_index2 = head;

        //第一个互换节点的前一个节点，从head开始向后走i-2步到达
        while (fstep--)
            before_index1 = List[before_index1].next;
        //第二个互换节点的前一个节点，从head开始向后走j-2步到达
        while (rstep--)
            before_index2 = List[before_index2].next;

        //下面处理两个节点与前后节点的关系

        int index1 = List[before_index1].next;
        int index2 = List[before_index2].next;
        if (List[index1].next != index2) //要交换的节点不相邻，需要给两个点连各自左右的两条链，共四条链
        {
            int next1 = List[index1].next;
            int next2 = List[index2].next;
            //把index2插到iindex1原先的位置
            List[before_index1].next = index2; //1
            List[index2].next = next1;         //2
            //把index1插到index2原先的位置
            List[before_index2].next = index1; //3
            List[index1].next = next2;         //4
        }
        else //交换的节点是相邻节点，需要连接第一个节点前的一条链，两个节点中间的一条链，第二个节点后的一条链
        {
            List[before_index1].next = index2; //1
            int next2 = List[index2].next;
            List[index2].next = index1; //2
            List[index1].next = next2;  //3
        }
    }
}
void PrintList()
{
    int cur = head, i = N;
    while (i--)
    {

        if (List[cur].next == -1)
        {
            printf("%05d %d %d\n", cur, List[cur].data, List[cur].next);
            break;
        }
        printf("%05d %d %05d\n", cur, List[cur].data, List[cur].next);
        cur = List[cur].next;
    }
}

int main()
{
    Input();
    ReverseList();
    PrintList();
    return 0;
}
