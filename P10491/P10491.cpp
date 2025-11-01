#include <bits/stdc++.h>
const int MAX = 2e2;

int n,m,ex,ey;
char mp[MAX][MAX];
bool vis[MAX][MAX];
std::pair<int,int> dis[8] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
std::queue<std::tuple<int,int,int> > que;

bool in(int x,int y);

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            std::cin >> mp[i][j];
            if(mp[i][j] == 'K') que.push({i,j,0});
            if(mp[i][j] == 'H') ex = i,ey = j;
        }
    for(;!que.empty();que.pop()){
        auto [x,y,d] = que.front();
        if(!in(x,y) || vis[x][y] || mp[x][y] == '*') continue;
        vis[x][y] = 1;
        if(x == ex && y == ey){
            std::cout << d << '\n';
            return 0;
        }
        for(auto [dx,dy] : dis){
            dx += x,dy += y;
            que.push({dx,dy,d + 1});
        }
    }
    std::cout << -1 << '\n';
    return 0;
}

bool in(int x,int y) {return 1 <= x && x <= n && 1 <= y && y <= m;}