#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m,his[MAX],in[MAX],out[MAX];
std::vector<int> ans,g[MAX];

void dfs(int u){
    for(int &i = his[u];i < g[u].size();)
        dfs(g[u][i++]);
    ans.push_back(u);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int u,v,i = 1;i <= m;i++){
        std::cin >> u >> v;
        out[u]++,in[v]++;
        g[u].push_back(v);
    }
    int s = 1;
    int fs = 0,ft = 0;
    for(int i = 1;i <= n;i++){
        if(out[i] == in[i] + 1) {s = i; fs++; continue;} 
        if(in[i] == out[i] + 1) {ft++; continue;}
        if(in[i] != out[i]){
            std::cout << "No\n";
            return 0;
        }
    }
    if(fs != ft || fs > 1 || ft > 1){
        std::cout << "No\n";
            return 0;
    }
    for(int i = 1;i <= m;i++)
        std::sort(g[i].begin(),g[i].end());
    dfs(s);
    std::reverse(ans.begin(),ans.end());
    for(auto i : ans) std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}