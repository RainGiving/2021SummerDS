#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
#include <iostream>
using namespace std;
int N;
struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int Root = Null;
    int check[MaxTree];
    cin >> N;
    if (N)
    {
        for (int i = 0; i < N; i++)
            check[i] = 0;
        char cl, cr;
        for (int i = 0; i < N; i++)
        {
            cin >> T[i].Element >> cl >> cr;
            //处理左孩子
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;

            //处理右孩子
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;
        }
        //查找根节点
        for (int i = 0; i < N; i++)
            if (!check[i])
            {
                Root = i;
                break;
            }
    }
    return Root;
}

bool Isomorphic(Tree R1, Tree R2)
{
    if (R1 == Null && R2 == Null)
        return 1; //全为空，默认同构
    if (R1 == Null && R2 != Null || R1 != Null && R2 == Null)
        return 0;                                                                                         //一个空一个不空，不可能同构
    if (T1[R1].Element != T2[R2].Element)                                                                 //根节点不同
        return 0;                                                                                         //树根的值不同，不可能同构
    if (T1[R1].Left == Null && T2[R2].Left == Null)                                                       //左节点全为空                                                      //左子树都为空
        return Isomorphic(T1[R1].Right, T2[R2].Right);                                                    //判断右节点是不是同构                                                   //判断右子树是否同构
    if (T1[R1].Left != Null && T2[R2].Left != Null && T1[T1[R1].Left].Element == T2[T2[R2].Left].Element) //两树的左子树都不为空且左子树元素相同
        return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));          //判断两树的左子树是否同构，右子树是否同构
    else
        return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left)); //一个树的左子树，右子树分别是否和另一个树的右子树，左子树同构
}

int main()
{
    Tree R1, R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);

    if (Isomorphic(R1, R2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}