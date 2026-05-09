#include <bits/stdc++.h>

struct node{
    int x,y,t;
};

const int MAX = 500;
int n,m,x,y;
int dir[8][2] = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
int ans[MAX][MAX];
bool vis[MAX][MAX];

bool in(int x,int y){return x >= 1 && x <= n && y >= 1 && y <= m;}

std::queue<node> q;
void bfs(){
    q.push({x,y,0});
    vis[x][y] = 1;
    ans[x][y] = 0;
    while(!q.empty()){
        auto [x,y,t] = q.front();
        q.pop();
        for(int i = 0;i < 8;i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(in(tx,ty) && !vis[tx][ty]){
                q.push({tx,ty,t + 1});
                vis[tx][ty] = 1;
                ans[tx][ty] = t + 1;
            }
        }
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> x >> y;
    bfs();
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(vis[i][j]){
                std::cout << ans[i][j] << ' ';
            }
            else{
                std::cout << -1 << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}