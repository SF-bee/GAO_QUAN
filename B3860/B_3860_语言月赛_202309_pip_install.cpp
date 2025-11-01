#include <bits/stdc++.h>

const int MAX = 5e3 + 5;
int n,ans;
std::vector<int> e[MAX];
bool vis[MAX];

void dfs(int d){
    vis[d] = 1;
    ans++;
    for(auto i : e[d])
        if(!vis[i])
            dfs(i);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 1;i <= n;i++){
        int x,v;
        std::cin >> x;
        for(int j = 0;j < x;j++){
            std::cin >> v;
            e[i].push_back(v);
        }
    }

    dfs(1);
    std::cout << ans;
    return 0;
}