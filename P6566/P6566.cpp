#include <bits/stdc++.h>
const int MAX = 1505;

int n,m,sq;
std::map<int,int> galaxy;
std::array<std::pair<int,int>,8> dis = {std::pair<int,int>{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
char maze[MAX][MAX];
bool vis[MAX][MAX];

bool in(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}

void dfs(int x,int y){
    sq++;
    vis[x][y] = 1;
    for(auto [dx,dy] : dis){
        dx += x;
        dy += y;
        if(!vis[dx][dy] && in(dx,dy) && maze[dx][dy] == '*')
            dfs(dx,dy);
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> maze[i][j];
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(!vis[i][j] && maze[i][j] == '*'){
                sq = 0;
                dfs(i,j);
                galaxy[sq]++;
            }
        }
    }
    std::cout << galaxy.size() << ' ';
    int maxa = 0;
    for(auto [sq,cnt] : galaxy)
        maxa = std::max(maxa,int(sq * cnt));
    std::cout << maxa << '\n';
    return 0;
}