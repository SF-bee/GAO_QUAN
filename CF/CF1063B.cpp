/*
变式最短路：
记录
*/

#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n,m,r,c,x,y;
char maze[MAX][MAX];
int dis[MAX][MAX];
bool vis[MAX][MAX];
struct node {
    int px,py;
    int ml; //左移次数
    bool operator < (const node &rhs) const {
        return ml > rhs.ml;
    }
};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> r >> c >> x >> y;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++)
            std::cin >> maze[i][j];
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int val[4] = {0,1,0,0};
    auto in = [&](int x,int y) {
        return maze[x][y] == '.' && 1 <= x && x <= n && 1 <= y && y <= m;
    };
    memset(dis,0x3f,sizeof(dis));
    std::priority_queue<node> que;
    for(que.push({r,c,dis[r][c] = 0});!que.empty();) {
        auto [nx,ny,d] = que.top(); que.pop();
        if(vis[nx][ny]) continue;
        if (d > x || d > y + c - ny) continue;
        vis[nx][ny] = 1;
        for(int dir = 0;dir < 4;dir++) {
            int tx = nx + dx[dir];
            int ty = ny + dy[dir];
            int nd = d + val[dir];
            if(!in(tx,ty)) continue;

            if(nd < dis[tx][ty])
                que.push({tx,ty,dis[tx][ty] = nd});
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(vis[i][j]) cnt++;
    std::cout << cnt << '\n';
    return 0;
}