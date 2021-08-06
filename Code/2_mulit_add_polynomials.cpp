#include <iostream>
#include <cstdio>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;  //系数
    int expon; //指数
    Polynomial link;
};

void Attach(int c, int e, Polynomial *pRear)
{
    //建立一个新节点，并对其进行赋值
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    //将之前的Rear指向新建的节点
    (*pRear)->link = P;
    //将Rear设置为新建的节点，为下一次插入准备
    *pRear = P;
}

Polynomial ReadPoly()
{
    int c, e, cnt;
    Polynomial P, Rear, t;

    cin >> cnt;
    P = (Polynomial)malloc(sizeof(struct PolyNode)); //链表头空节点
    P->link = NULL;
    Rear = P;
    while (cnt--)
    {
        cin >> c >> e;
        Attach(c, e, &Rear); //不断将新节点插到尾部
    }
    t = P;
    P = P->link;
    free(t);  //
    return P; //返回读入链表的头节点
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear; //记录头节点
    while (P1 && P2)
    {
        if (P1->expon == P2->expon)
        {
            sum = P1->coef + P2->coef;
            if (sum)
                Attach(sum, P1->expon, &rear);
            P1 = P1->link;
            P2 = P2->link;
        }
        else if (P2->expon <= P1->expon)
        {
            Attach(P1->coef, P1->expon, &rear);
            P1 = P1->link;
        }
        else
        {
            Attach(P2->coef, P2->expon, &rear);
            P2 = P2->link;
        }
    }
    while (P1)
    {
        Attach(P1->coef, P1->expon, &rear);
        P1 = P1->link;
    }
    while (P2)
    {
        Attach(P2->coef, P2->expon, &rear);
        P2 = P2->link;
    }
    rear->link = NULL;
    temp = front;
    front = front->link; //令front指向第一个非零项
    free(temp);
    return front;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
    if (!(P1 && P2)) // P1或P2为空都返回NULL
        return NULL;
    Polynomial P, rear, t1, t2, t;
    int c, e;
    t1 = P1, t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    rear = P;
    while (t2) // P1的第一项乘以P2，得到P
    {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1)
    {
        t2 = P2, rear = P;
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (rear->link && e < rear->link->expon)
                rear = rear->link;
            if (rear->link && rear->link->expon == e)
                if (rear->link->coef + c)
                    rear->link->coef += c;
                else
                {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            else
            {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);
    return P;
}

void PrintPoly(Polynomial P)
{
    int flag = 0;
    if (!P)
    {
        printf("0 0\n");
        return;
    }
    while (P)
    {
        if (!flag)
            flag = 1; //确保第一个输出的前面没有空格
        else
            printf(" ");
        cout << P->coef << ' ' << P->expon;
        P = P->link;
    }
    cout << endl;
}

int main()
{
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);
    return 0;
}