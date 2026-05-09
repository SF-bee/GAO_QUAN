#include <bits/stdc++.h>
typedef long long ll;

const int MAX = 1e5 + 5;
int n;
std::vector<int> mp[MAX];
std::vector<ll> stack;
int w[MAX],c[MAX],ans[MAX];

void dfs(int d){
    stack.push_back(stack.back() + w[d]);
    int p = std::lower_bound(stack.begin(),stack.end(),stack.back() - c[d]) - stack.begin();
    ans[d] = stack.size() - p - 1;
    for(auto i : mp[d]) dfs(i);
    stack.pop_back();
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 2;i <= n;i++){
        int p;
        std::cin >> p;
        mp[p].push_back(i);
    }
    for(int i = 1;i <= n;i++) std::cin >> w[i];
    for(int i = 1;i <= n;i++) std::cin >> c[i];
    
    stack.push_back(0);
    dfs(1);
    for(int i = 1;i <= n;i++)
        std::cout << ans[i] << ' ';
    return 0;
}