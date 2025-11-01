#include <bits/stdc++.h>
const int MAX = 20;

int n,m,p,k,s;
int key[MAX][MAX],maze[MAX][MAX][MAX][MAX];
int vis[20000][MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool in(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}

int main(){
    #if !ONLINR_JUDEGE
    freopen("P4011.in","r",stdin);
    freopen("P4011.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> p >> k;
    for(int i = 1;i <= k;i++){
        int x1,y1,x2,y2,g;
        std::cin >> x1 >> y1 >> x2 >> y2 >> g;
        if(g) maze[x1][y1][x2][y2] = g,maze[x2][y2][x1][y1] = g;
        else maze[x1][y1][x2][y2] = -1,maze[x2][y2][x1][y2] = -1;
    }
    std::cin >> s;
    for(int i = 1;i <= s;i++){
        int x,y,q;
        std::cin >> x >> y >> q;
        key[x][y] = q;
    }
    std::queue<std::tuple<int,std::pair<int,int>,int> > que;
    if(key[1][1]) que.push({1 << key[1][1] - 1,{1,1},0});
    else que.push({0,{1,1},0});
    for(std::tuple<int,std::pair<int,int>,int> u;!que.empty();){
        u = que.front(),que.pop();
        int x = std::get<1>(u).first,y = std::get<1>(u).second;
        int ky = std::get<0>(u),d = std::get<2>(u);
        if(x == n && y == m){
            std::cout << std::get<2>(u) << '\n';
            return 0;
        }
        if(vis[ky][x][y]) continue;
        vis[ky][x][y] = 1;
        // std::cout << '[' << ky << ']' << x << ' ' << y << '\n';
        // std::cout << ky << ' ' << x << ' ' << y << '\n';
        for(int i = 0;i < 4;i++){
            int tx = x + dx[i],ty = y + dy[i],g = maze[x][y][tx][ty];
            if(g == -1 || !in(tx,ty) || !(ky & (1 << g - 1))) continue;
            if(key[tx][ty]) que.push({ky | (1 << key[tx][ty] - 1),{tx,ty},d + 1});
            else que.push({ky,{tx,ty},d + 1});
        }
    }
    std::cout << -1;
    return 0;
}