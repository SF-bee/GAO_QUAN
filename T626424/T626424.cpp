#include <bits/stdc++.h>
const int MAX = 5e2 + 5;

int n,m;
int e[MAX][MAX],maxa[MAX][MAX]; //maxa[i][j]表示以i为家,在i，j之间开传送门时，x到最远点的距离

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    memset(e,0x3f,sizeof(e));

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) e[i][i] = 0;
    for(int u,v,w,i = 1;i <= m;i++){
        std::cin >> u >> v >> w;
        e[u][v] = w;
    }
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                e[i][j] = std::min(e[i][j],e[i][k] + e[k][j]);
    for(int x = 1;x <= n;x++){
        for(int b = 1;b <= n;b++){
            for(int i = 1;i <= n;i++){
                maxa[x][b] = std::max(maxa[x][b],std::min(e[x][i],e[b][i]));
            }
        }
    }
    int mina = 0x3f3f3f3f;
    for(int x = 1;x <= n;x++)
        for(int b = 1;b <= n;b++) if(maxa[x][b] != 0)
            mina = std::min(mina,maxa[x][b]);
    std::cout << mina << '\n';
    return 0;
}