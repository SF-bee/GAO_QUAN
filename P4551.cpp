#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

struct edge{
    int to,w;
};
int n,tot,cnt[MAX],trie[MAX * 31][2];
std::vector<edge> g[MAX];

void dfs(int d,int fa){
    for(auto [to,w] : g[d]) if(to != fa){
        cnt[to] = cnt[d] ^ w;
        dfs(to,d);
    }
}

namespace Trie{
    void insert(int val){
        int x = 0;
        for(int i = (1 << 30);i;i >>= 1){
            int a = bool(val & i);
            if(!trie[x][a]) 
                trie[x][a] = ++tot;
            x = trie[x][a];
        }
    }
    int find(int val){
        int ans = 0,x = 0;
        for(int i = (1 << 30);i;i >>= 1){
            int a = bool(val & i);
            if(trie[x][!a]){
                x = trie[x][!a];
                ans += i;
            }
            else
                x = trie[x][a];
        }
        return ans;
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int u,v,w,i = 1;i < n;i++){
        std::cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++)
        Trie::insert(cnt[i]);
    int ans = 0;
    for(int u = 1;u <= n;u++)
        ans = std::max(ans,Trie::find(cnt[u]));
    std::cout << ans << '\n';
    return 0;
}