#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n,p,sum;
int dis[MAX],g[MAX][MAX];
bool vis[MAX];
std::pair<int,int> node[MAX];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> p;
    memset(g,0x3f,sizeof(g));
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i <= n;i++)
        std::cin >> node[i].first >> node[i].second;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            int t = (node[i].first - node[j].first) * (node[i].first - node[j].first) + 
            (node[i].second - node[j].second) * (node[i].second - node[j].second);
            if(t >= p) g[i][j] = t;
        }
    //prim
    for(int i = 1;i <= n;i++)
        dis[i] = g[1][i];
    vis[1] = 1;
    for(int i = 1;i <= n - 1;i++){
        int mval = 0x3f3f3f3f,mid = 0;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && dis[j] < mval)
                mval = dis[j],mid = j;
        if(mval == 0x3f3f3f3f){
            std::cout << -1 << '\n';
            return 0;
        }
        vis[mid] = 1; sum += mval;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && g[mid][j] < dis[j])
                dis[j] = g[mid][j];
    }
    std::cout << sum << '\n';
    return 0;
}