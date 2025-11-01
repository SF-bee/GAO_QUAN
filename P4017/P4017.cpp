#include <bits/stdc++.h>
#define int long long
const int MAX = 5e3 + 5;
const int MOD = 80112002;

int n,m,ans;
int f[MAX],in[MAX];
std::vector<int> out[MAX];

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u,v;
        std::cin >> u >> v;
        out[u].push_back(v);
        in[v]++;
    }
    std::queue<int> que;
    for(int i = 1;i <= n;i++)
        if(in[i] == 0){
            que.push(i);
            f[i] = 1;
        }
    while (!que.empty()){
        int p = que.front();
        que.pop();
        for(auto i : out[p]){
            f[i] = (f[i] % MOD + f[p] % MOD) % MOD;
            in[i]--;
            if(!in[i]){
                que.push(i);
            }
        }
    }
    for(int i = 1;i <= n;i++)
        if(out[i].size() == 0){
            ans = (ans % MOD + f[i] % MOD) % MOD;
        }
    std::cout << ans;
    return 0;
}