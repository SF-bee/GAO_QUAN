#include <bits/stdc++.h>
const int MAX = 5e4 + 5;

int n,c[MAX];
std::bitset<MAX> cnt[MAX];
std::vector<int> book;
std::vector<int> g[MAX];

void dfs(int d,int fa){
    for(auto i : g[d]) if(i != fa){
        dfs(i,d);
    }
    cnt[fa] ^= cnt[d]; 
}

int main(){
    // #if !ONLINE_JUDGE
    // freopen("tree_ex.in","r",stdin);
    // freopen("tree_ex.out","w",stdout);
    // #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> c[i],book.push_back(c[i]);
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++){
        c[i] = std::lower_bound(book.begin(),book.end(),c[i]) - book.begin();
        cnt[i].set(c[i],1);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) std::cout << cnt[i].count() << '\n';
    return 0;
}