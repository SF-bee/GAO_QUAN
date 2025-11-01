#include <bits/stdc++.h>
const int MAX = 2e6;

int n,k,vis[MAX];
std::vector<int> nte,ans;

void dfs(int d){
    if(d == (1 << n) + 1){
        for(auto i : ans)
            std::cout << i << ' ';
        std::cout << '\n';
        exit(0);
    }
    for(auto i : nte){
        int nxt = ans.back() ^ i;
        if(!vis[nxt]){
            ans.push_back(nxt);
            vis[nxt] = 1;
            dfs(d + 1);
            ans.pop_back();
            vis[nxt] = 0;
        }
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;

    for(int i = 0;i < (1 << n);i++)
        if(std::__popcount(i) == k){
            nte.push_back(i);
        }
    ans.push_back(0);
    vis[0] = 1;
    dfs(2);
    return 0;
}