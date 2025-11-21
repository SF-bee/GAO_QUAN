#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m,E,T;
bool vis[MAX];
int p[MAX],ind[MAX],ans[MAX];
std::vector<int> g[MAX];
std::vector<std::pair<int,int> > e;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m >> E;
    e.resize(E + 1);
    for(int i = 1;i <= E;i++)
        std::cin >> e[i].first >> e[i].second;
    std::cin >> T;
    for(int i = 1;i <= T;i++)
        std::cin >> p[i],vis[p[i]] = 1;
    for(int i = 1;i <= E;i++) if(!p[i]){
        g[e[i].first].push_back(e[i].second);
        g[e[i].second].push_back(e[i].first);
    }
    return 0;
}