#include <bits/stdc++.h>
const int N = 1e5 + 5;

int n,m,q,u,v,t,a[N];
std::queue<int> old,l,r;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> q >> u >> v >> t;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    std::sort(a + 1,a + n + 1,std::greater<int>());
    for(int i = 1;i <= n;i++) old.push(a[i]);
    int tap = 0;
    for(int et,i = 1;i <= m;i++){
        et = std::max({(!old.empty() ? old.front(): INT_MIN),
                         (!l.empty() ?   l.front(): INT_MIN),
                         (!r.empty() ?   r.front(): INT_MIN)});
        if(!old.empty() && et == old.front()) old.pop();
        else if(!l.empty() && et == l.front()) l.pop();
        else if(!r.empty() && et == r.front()) r.pop();
        et += tap;
        int etl = 1ll * et * u/v;
        int etr = et - etl;
        tap += q;
        l.push(etl - tap),r.push(etr - tap);
        if(i % t == 0) std::cout << et << ' ';
    }
    std::cout << '\n';
    for(int et,i = 1;i <= n + m;i++){
        et = std::max({(!old.empty() ? old.front(): INT_MIN),
                         (!l.empty() ?   l.front(): INT_MIN),
                         (!r.empty() ?   r.front(): INT_MIN)});
        if(!old.empty() && et == old.front()) old.pop();
        else if(!l.empty() && et == l.front()) l.pop();
        else if(!r.empty() && et == r.front()) r.pop();
        if(i % t == 0) std::cout << et + tap << ' ';
    }
    return 0;
}