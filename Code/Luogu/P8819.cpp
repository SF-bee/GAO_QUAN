#include <bits/stdc++.h>
using ull = unsigned long long;
const int MAX = 5e5 + 5;

int n,m,q;
ull spre[MAX],snow[MAX];
ull a[MAX],ide,sumn;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::mt19937 val(time(0));

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        a[i] = val(),sumn += a[i];
    for(int u,v,i = 1;i <= m;i++) {
        std::cin >> u >> v;
        ide += a[u];
        spre[v] += a[u];
        snow[v] = spre[v];
    }
    std::cin >> q;
    int op,u,v;
    while(q--) {
        std::cin >> op;
        switch (op) {
            case 1: //删除某边
                std::cin >> u >> v;
                ide -= a[u];
                snow[v] -= a[u];
                break;
            case 2: //删除某点的所有入边
                std::cin >> u;
                ide -= snow[u];
                snow[u] = 0;
                break;
            case 3: //添加某条边
                std::cin >> u >> v;
                ide += a[u];
                snow[v] += a[u];
                break;
            case 4: //添加某个点的所有入边
                std::cin >> u;
                ide += spre[u] - snow[u];
                snow[u] = spre[u];
                break;
        }
        std::cout << (ide == sumn ? "YES\n" : "NO\n");
    }
    return 0;
}