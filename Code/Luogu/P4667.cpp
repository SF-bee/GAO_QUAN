#include <bits/stdc++.h>
const int MAX = 505;

int n,m;
char maze[MAX][MAX];
struct edge {
    std::pair<int,int> to;
    int dis;
    bool operator < (const edge &e) const {
        return dis > e.dis;
    }
};
int dist[MAX][MAX];
std::vector<edge> path[MAX][MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::memset(dist,0x3f,sizeof(dist));
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std::cin >> maze[i][j];
    auto in = [&](int x,int y){
        return 0 < x && x <= n + 1 && 0 < y && y <= m + 1;
    };
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int x1 = i, y1 = j;
            int x2 = i + 1, y2 = j + 1;
            int x3 = i, y3 = j + 1;
            int x4 = i + 1, y4 = j;
            if (maze[i][j] == '\\'){
                path[x1][y1].push_back({{x2, y2}, 0});
                path[x2][y2].push_back({{x1, y1}, 0});
                path[x3][y3].push_back({{x4, y4}, 1});
                path[x4][y4].push_back({{x3, y3}, 1});
            }
            else { // '/'
                path[x3][y3].push_back({{x4, y4}, 0});
                path[x4][y4].push_back({{x3, y3}, 0});
                path[x1][y1].push_back({{x2, y2}, 1});
                path[x2][y2].push_back({{x1, y1}, 1});
            }
        }
    }
    std::priority_queue<edge> q;
    for(q.push({{1,1},0});!q.empty();) {
        auto [u,d] = q.top(); q.pop();
        if(dist[u.first][u.second] <= d) continue;
        dist[u.first][u.second] = d;
        for(auto &e : path[u.first][u.second]) {
            auto [v,dis] = e;
            if(in(v.first,v.second) && dist[v.first][v.second] > d + dis)
                q.push({v,d + dis});
        }
    }
    if(dist[n+1][m+1] == 0x3f3f3f3f) std::cout << "NO SOLUTION\n";
    else std::cout<< dist[n+1][m+1] << "\n";
    return 0;
}