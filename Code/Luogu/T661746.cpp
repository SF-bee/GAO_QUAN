#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

std::vector<int> g[MAX],eg[MAX];
int dfn[MAX],low[MAX],sta[MAX];
bool ins[MAX];
int top,cnt,tim,siz[MAX],ecc[MAX],r[MAX],b[MAX];

struct edge {int u,v,c,dis;};
std::vector<edge> e;
std::vector<int> ee[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m;
    std::cin >> n >> m;
    for(int u,v,op,i = 1;i <= m;i++){
        std::cin >> u >> v >> op;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u,v,op,0});
    }
    auto tarjan = [&](auto &dfs,int u,int fa) -> void{
        bool flag = false;
        dfn[u] = low[u] = ++tim;
        ins[sta[++top] = u] = true;
        for(auto v : g[u]){
            if(!dfn[v]){
                dfs(dfs,v,u);
                low[u] = std::min(low[u],low[v]);
            }
            else{
                if(v != fa || flag)
                    low[u] = std::min(low[u],dfn[v]);
                else flag = true;
            }
        }
        if(dfn[u] == low[u]){
            cnt++;
            do{
                ecc[sta[top]] = cnt;
                siz[cnt]++;
                ins[sta[top]] = false;
            }while(sta[top--] != u);
        }
    };
    for(int i = 1;i <= n;i++) if(!dfn[i])
        tarjan(tarjan,i,0);
    for(int i = 0;i < e.size();i++){
        auto [u,v,c,dis] = e[i];
        if(ecc[u] == ecc[v]){
            ee[ecc[u]].push_back(i);
            if(c == 1) r[ecc[u]]++;
            else b[ecc[u]]++;
        }
    }
    int res = 1;
    for(int i = 1;i <= cnt;i++){
        for(int j = 0;j < ee[i].size();j++)
            if(e[ee[i][j]].c == 1) e[ee[i][j]].dis = res++;
        for(int j = 0;j < ee[i].size();j++)
            if(e[ee[i][j]].c == 0) e[ee[i][j]].dis = res++;
    }
    for(int i = 0;i < m;i++){
        if(e[i].dis != 0) std::cout << e[i].dis << ' ';
        else std::cout << res++ << ' ';
    }
    std::cout << '\n';
    return 0;
}