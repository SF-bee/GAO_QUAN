#include <bits/stdc++.h>
const int MAX = 505;

struct node{int x,y,d;};

int n,m,p,q;
int a[MAX][MAX];
int vis[MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
std::queue<node> que;

bool in(int x,int y){return x >= 1 && x <= n && y >= 1 && y <= m;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> p >> q;
    for(int i = 0;i < MAX;i++)
        memset(vis[i],0x3f,sizeof(vis[i]));
    for(int i = 0;i < p;i++){
        int x,y;
        std::cin >> x >> y;
        que.push({x,y,0});
        vis[x][y] = 0;
    }
    while(!que.empty()){
        auto [x,y,d] = que.front();
        que.pop();
        for(int i = 0;i < 4;i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(vis[tx][ty] == 0x3f3f3f3f && in(tx,ty)){
                que.push({tx,ty,d + 1});
                vis[tx][ty] = std::min(vis[tx][ty],d + 1);
            }
        }
    }
    while(q--){
        int x,y;
        std::cin >> x >> y;
        std::cout << vis[x][y] << '\n';
    }
    return 0;
}