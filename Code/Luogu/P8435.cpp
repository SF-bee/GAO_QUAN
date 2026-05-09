#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,m;
std::vector<int> g[MAX];
int tim,dfn[MAX],low[MAX]; 
int top,sta[MAX];
int cnt;
std::vector<int> ans[MAX];

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u,v,i = 1; i <= m; i++) {
        std::cin >> u >> v;
        if(u == v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root;
    auto dfs = [&](auto &self, int u, int fa) -> void {
        dfn[u] = low[u] = ++tim;
        sta[++top] = u;
        if(u == root && g[u].size() == 0) {
            ans[++cnt].push_back(u);
            top--;
            return;
        }
        for(auto v : g[u]){
            if(!dfn[v]) {
                self(self,v,u);
                low[u] = std::min(low[u],low[v]);
                if(low[v] >= dfn[u]) {
                    cnt++;
                    do ans[cnt].push_back(sta[top--]);
                    while (sta[top + 1] != v);
                    ans[cnt].push_back(u);
                }
            }
            else if(v != fa) low[u] = std::min(low[u],dfn[v]);
        }
    };
    for (int i = 1;i <= n;i++) if (!dfn[i])
        root = i,dfs(dfs,i,i);
    
    std::cout << cnt << '\n';
    for(int i = 1;i <= cnt;i++) {
        std::cout << ans[i].size() << ' ';
        for(auto u : ans[i])
            std::cout << u << ' ';
        std::cout << '\n';
    }
    return 0;
}