#include <bits/stdc++.h>
#define Nanami return
#define Chiaki 0
using ll = long long;
const int MAX = 5e5 + 5;

//f_i 表示1~i的前缀中合法字串的数量
//g_i 表示以 i 结尾合法的字串数量
//l_i 表示 i 能匹配的最远位置
int n,fa[MAX];
ll f[MAX],g[MAX];
int top,stk[MAX];
std::vector<int> ga[MAX];
std::string s;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> s;
    s = '&' + s;
    for(int i = 2;i <= n;i++)
        std::cin >> fa[i],ga[fa[i]].push_back(i);
    auto dfs = [&](auto &dfs,int u) -> void{
        int mt = -1;
        if(s[u] == '(') stk[++top] = u;
        else if(top != 0){
                mt = stk[top--];
                g[u] = g[fa[mt]] + 1;
        }
        f[u] = f[fa[u]] + g[u];
        for(auto v : ga[u])
            dfs(dfs,v);
        if(mt != -1)
            stk[++top] = mt;
        else if(s[u] == '(')
            top--;
    };
    dfs(dfs,1);
    ll ans = 0;
    for(int i = 1;i <= n;i++)
        ans ^= i * f[i];
    std::cout << ans << '\n';
    Nanami Chiaki;
}