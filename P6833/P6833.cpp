#include <bits/stdc++.h>
#define int long long
const int MAX = 1e3 + 5;

int n,m,a,b,c;
int ans = 1e18,r[MAX][MAX],d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int dis[3][MAX][MAX];
bool vis[MAX][MAX];

bool in(int x,int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

void dijkstra(int x,int y,int p){
    std::priority_queue<std::pair<int,std::pair<int,int>> > q;
    memset(vis,0,sizeof(vis));
    q.push({-(dis[p][x][y] = r[x][y]),{x,y}});
    for(;!q.empty();){
        auto [tx,ty] = q.top().second; q.pop();
        if(vis[tx][ty]) continue;
        vis[tx][ty] = 1;
        for(int i = 0;i < 4;i++){
            auto dx = tx + d[i][0];
            auto dy = ty + d[i][1];
            if(in(dx,dy) &&dis[p][dx][dy] > dis[p][tx][ty] + r[dx][dy])
                q.push({-(dis[p][dx][dy] = dis[p][tx][ty] + r[dx][dy]),{dx,dy}});
        }
    }
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> a >> b >> c;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> r[i][j];
    memset(dis,0x3f,sizeof(dis));
    dijkstra(1,a,0);
    dijkstra(n,b,1);
    dijkstra(n,c,2);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            ans = std::min(ans,dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - r[i][j] * 2);
        }
    std::cout << ans << '\n';
    return 0;
}