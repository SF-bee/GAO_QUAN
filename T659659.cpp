#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int T;
int n,m;
std::vector<int> g[MAX];
int top,cnt,tim;
int sta[MAX],dfn[MAX],low[MAX],bcc[MAX];
bool ins[MAX];
std::vector<int> bg[MAX];
int ta,tb,dep[MAX];

void init(){
    top = cnt = tim = ta = tb = 0;
    std::memset(sta,0,sizeof(sta));
    std::memset(dfn,0,sizeof(dfn));
    std::memset(low,0,sizeof(low));
    std::memset(bcc,0,sizeof(bcc));
    std::memset(ins,0,sizeof(ins));
    std::memset(g,0,sizeof(g));
    std::memset(bg,0,sizeof(bg));
    std::memset(dep,0,sizeof(dep));
}
void tarjan(int u,int fa){
    bool flag = 0;
    dfn[u] = low[u] = tim++;
    ins[sta[++top] = u] = 1;
    for(auto v : g[u]){
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
        }
        else if(ins[v]){
            if (v != fa || flag)
                low[u] = std::min(low[u], dfn[v]);
            else
                flag = 1;
        }
    }
    if(dfn[u] == low[u]){
        cnt++;
        do{
            bcc[sta[top]] = cnt;
            ins[sta[top]] = 0;  
        } while (sta[top--] !=u);
    }
}

void dfs(int u,int fa,int d){
    dep[u] = d;
    if(dep[u] > dep[ta]) ta = u;
    for(auto v : bg[u]) if(v != fa)
        dfs(v,u,d + 1);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        init();
        std::cin >> n >> m;
        for(int u,v,i = 1;i <= m;i++){
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1;i <= n;i++) if(!dfn[i])
            tarjan(i,0);
        for(int u = 1;u <= n;u++)
            for(auto v : g[u]) if(bcc[u] != bcc[v])
                bg[bcc[u]].push_back(bcc[v]);
        dfs(1,0,1);
        tb = ta;
        ta = 0;
        std::memset(dep,0,sizeof(dep));
        dfs(tb,0,1);
        std::cout << cnt - dep[ta] << '\n';
    }
    return 0;
}