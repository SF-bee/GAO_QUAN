#include <bits/stdc++.h>

struct node{
    int id; //部件序号
    int p; //工序序号
};

const int MAX = 500;
int m,n;
int p[MAX],mac[MAX][MAX],tim[MAX][MAX]; //p[i]为第i个操作，mac[i][j]为第i个部件的第j个工序指定的机器，tim[i][j]为第i个部件的第j个工序所需的时间
int now[MAX]; //now[i]为第i个部件当前的工序
std::vector<node> rob;

void read(){
    std::cin >> m >> n;
    for(int i = 1;i <= n * m;i++) std::cin >> p[i];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            std::cout << mac[i][j];
            now[i] = 1;
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cout << tim[i][j];
}

void arr(){
    
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    read();
    return 0;
}