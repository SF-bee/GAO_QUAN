//尝试Dance-links算法
/*
1、构造0-1矩阵
决策行定义：
在x行，y列填入z，那么这个状态在第x*y*z行
约束列定义：
对于每一个决策（x,y,z）
如果 (x,y) 填入了 z，那么 (x,y) 不能再填数 编号为 x*y = 1~81
如果 x 行填入了 z，那么 x 行不能再填 z; 编号为 81 + x*z = 82~162
如果 y 列填入了 z，那么 y 列不能再填 z; 编号为 162 + y*z = 163~243
如果 第n个九宫格填入了 z,那么第 n 个九宫格不能再填 z; 编号为 243 + n*z = 243~323

问题转化为已经选择了若干行，再选择若干行，使得每一列都恰好只有一个1

*/
#include <bits/stdc++.h>
const int MAX = 3e5;

struct Node { //链表的结点
    int u,d,l,r;
    int x,y,z;
    int sz;
}list[MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    for(int i = 1;i <= 10;i++)
        for(int j = 1;j <= 10;j++)
            std::cin >> maz[i][j];
    return 0;
}