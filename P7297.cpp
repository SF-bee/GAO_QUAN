#include <bits/stdc++.h>
const int MAX = 5e4 + 5;
const int K = 55;

int n,k,b[MAX];
bool s[K][K];
struct node {
    int col,to,dis;
};
std::vector<node> g[K][MAX]; //i表示颜色，j表示节点编号
int dis[K][MAX];
bool vis[K][MAX];

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::memset(dis,0x3f,sizeof(dis));
    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
        std::cin >> b[i];
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= k;j++) {
            char ch;
            std::cin >> ch;
            s[i][j] = ch - '0';
        }
    }
    for(int i = 1;i <= n;i++) {
        if(i != n) g[b[i]][i].push_back({b[i],i + 1,1});
        for(int j = 1;j <= k;k++)
            g[b[i]][i].push_back({j,i,0});
    }
    return 0;
}