//尝试Dance-links算法
/*
1、构造0-1矩阵
决策行定义：
在x行，y列填入z，那么这个状态在第 81(x-1) + 9(y-1) + (z-1) + 1行
约束列定义：
对于每一个决策（x,y,z）
如果 (x,y) 填入了 z，那么 (x,y) 不能再填数 编号为 9*(x-1) + (y-1) + 1 = 1~81
如果 x 行填入了 z，那么 x 行不能再填 z; 编号为 81 + 9*(x-1) + (z-1) + 1 = 82~162
如果 y 列填入了 z，那么 y 列不能再填 z; 编号为 162 + 9*(y-1) + (z-1) + 1 = 163~243
如果第 n 个九宫格填入了 z,那么第 n 个九宫格不能再填 z; 编号为 243 + 9*(n-1) + (z-1) + 1 = 244~324

问题转化为已经选择了若干行，再选择若干行，使得每一列都恰好只有一个1

*/
#include <bits/stdc++.h>
const int MAX = 3e5;

int maz[10][10];
int scor[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,6,6,6,6,6,6},
    {0,6,7,7,7,7,7,7,7,6},
    {0,6,7,8,8,8,8,8,7,6},
    {0,6,7,8,9,9,9,8,7,6},
    {0,6,7,8,9,10,9,8,7,6},
    {0,6,7,8,9,9,9,8,7,6},
    {0,6,7,8,8,8,8,8,7,6},
    {0,6,7,7,7,7,7,7,7,6},
    {0,6,6,6,6,6,6,6,6,6}
};
int maxa;
struct DLX {
    int n,m;  //矩阵的大小
    int L[MAX],R[MAX],U[MAX],D[MAX];  //左邻右舍
    int rowx[MAX],rowy[MAX],rowz[MAX];
    int row[MAX],col[MAX];  //所在的行列
    int siz[MAX];  //每列的节点数
    std::vector<int> ans;
    size_t sz;  //目前最大的节点的编号

    DLX() {
        m = 324;
        for(int i = 0;i <= m;i++) {
            L[i] = i - 1;
            R[i] = i + 1;
            U[i] = D[i] = i;
            siz[i] = 0;
        }
        L[0] = m; R[m] = 0; sz = m;
        n = 0;
    }
    int getG(int x,int y) {return 3 * ((x - 1) / 3) + ((y - 1) / 3) + 1;}
    int id1(int x,int y) {return 9*(x-1) + (y-1) + 1;}
    int id2(int x,int z) {return 81 + 9*(x-1) + (z-1) + 1;}
    int id3(int y,int z) {return 162 + 9*(y-1) + (z-1) + 1;}
    int id4(int x,int y,int z) {return 243 + 9*(getG(x,y)-1) + (z-1) + 1;}
    void addRow(int x,int y,int z) {  //添加一个决策
        ++n;
        int first = sz + 1;
        rowx[n] = x,rowy[n] = y,rowz[n] = z;
        int cols[4] = {id1(x,y),id2(x,z),id3(y,z),id4(x,y,z)};
        for(int i = 0;i < 4;i++) {
            int c = cols[i]; ++sz;
            row[sz] = n;
            col[sz] = c;

            L[sz] = sz - 1;
            R[sz] = sz + 1;
            U[sz] = U[c];
            D[sz] = c;
            D[U[c]] = sz;
            U[c] = sz;
            ++siz[c];
        }
        L[first] = sz;
        R[sz] = first;
    }
    void cover(int c) {
        R[L[c]] = R[c];
        L[R[c]] = L[c];
        for(int i = D[c];i != c;i = D[i]) {
            for(int j = R[i];j != i;j = R[j]) {
                D[U[j]] = D[j];
                U[D[j]] = U[j];
                --siz[col[j]];
            }
        }
    }
    void recover(int c) {
        for(int i = U[c];i != c;i = U[i]) {
            for(int j = L[i];j != i;j = L[j]) {
                ++siz[col[j]];
                D[U[j]] = j;
                U[D[j]] = j;
            }
        }
        R[L[c]] = c;
        L[R[c]] = c;
    }
    void GetAns() {
        int res = 0;
        for(auto i : ans) {
            int x = rowx[i];
            int y = rowy[i];
            int z = rowz[i];
            res += scor[x][y] * z;
        }
        maxa = std::max(maxa,res);
    }
    void dance() {
        if(R[0] == 0) {
            GetAns();
            return;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(siz[i] < siz[c]) c = i;
        cover(c);
        for(int i = D[c];i != c;i = D[i]) {
            ans.emplace_back(row[i]);
            for(int j = R[i];j != i;j = R[j])
                cover(col[j]);
            dance();
            for(int j = L[i];j != i;j = L[j])
                recover(col[j]);
            ans.pop_back();
        }
        recover(c);
    }
}dls;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    for(int i = 1;i <= 9;i++)
        for(int j = 1;j <= 9;j++) {
            std::cin >> maz[i][j];
            if(maz[i][j] == 0)
                for(int n = 1;n <= 9;n++)
                    dls.addRow(i,j,n);
            else dls.addRow(i,j,maz[i][j]);
        }
    dls.dance();
    if(maxa == 0) std::cout << -1;
    else std::cout << maxa << '\n';
    return 0;
}