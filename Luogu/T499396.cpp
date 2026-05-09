#include <bits/stdc++.h>
#define int long long  //十年OI一场空（
const int MAX = 2e5 + 5;
const int MOD = 1e4;

int n,q,a[MAX];
bool vis[MAX];
std::vector<int> g[MAX];
int lg[MAX],fa[20][MAX],f[20][MAX],sum[20][MAX],nxt[MAX];  //lg log_2的结果，fa祖先，f不包括起点的最大值，sum路径不包括终点的积，nxt停在第几级祖先
int dep[MAX];

void input(){
    std::cin >> n >> q;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],
        sum[0][i] = a[i] % MOD;
    for(int i = 1;i < n;i++){
        int u,v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int d){
    vis[d] = true;
    f[0][d] = a[d];
    for(auto i : g[d]){
        if(!vis[i]){
            fa[0][i] = d;
            dep[i] = dep[d] + 1;
            dfs(i);
        }
    }
}

void init(){
    //初始化
    for(int i = 2;i <= n;i++)
        lg[i] = lg[i >> 1] + 1;
    for(int j = 1;(1 << j) <= n;j++)
        for(int i = 1;i <= n;i++){
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
            f[j][i] = std::max(f[j - 1][i],f[j - 1][fa[j - 1][i]]);
            sum[j][i] = sum[j - 1][i] * sum[j - 1][fa[j - 1][i]] % MOD;
        }
}

int ask(int x){
    int ans = a[x] % MOD;
    int pos = fa[0][x];
    for(int k = 20;k >= 0;k--){
        if(dep[pos] >= (1 << k) && f[k][pos] < a[x]){
            ans = ans * sum[k][pos] % MOD;
            pos = fa[k][pos];
        }
    }
    return ans;
}

void output(){
    while(q--){
        int x;
        std::cin >> x;
        std::cout << ask(x) << '\n';
    }
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    input();  //输入
    dep[1] = 1;
    dfs(1);  //深搜处理父子关系
    //假设有一座很高的山在所有山之后
    init();  //预处理
    output();  //查询
    return 0;
}