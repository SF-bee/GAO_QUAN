#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

int n,m;
std::vector<int> g[MAX],sg[MAX];
int sta[MAX],dfn[MAX],low[MAX],sc[MAX],cnt,top,tim = 1;
bool in[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int a,x,b,y,i = 1;i <= m;i++){
        std::cin >> a >> x >> b >> y;
        g[(x ? a : a + n)].push_back((y ? b + n : b));
        g[(y ? b : b + n)].push_back((x ? a + n : a));
    }

    auto dfs = [&](auto & dfs,int u) -> void
    {
        low[u] = dfn[u] = tim++;
        sta[++top] = u;
        in[u] = true;
        for(auto v : g[u]){
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = std::min(low[u],low[v]);
            }
            else if(in[v])
                low[u] = std::min(low[u],dfn[v]);     
        }
        if(dfn[u] == low[u]){
            cnt++;
            do{
                sc[sta[top]] = cnt;
                in[sta[top]] = false;
            } while (sta[top--] != u);
        }
    };
    for(int i = 1;i <= n * 2;i++)
        if(!dfn[i]) dfs(dfs,i);
    for(int i = 1;i <= n;i++)
        if(sc[i] == sc[i + n]){
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
    std::cout << "POSSIBLE\n";
    for(int i = 1;i <= n;i++)
        std::cout << (sc[i] < sc[i + n] ? 0 : 1) << " \n"[i == n];
    return 0;
}