#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n,m;
ll v[MAX],cnt[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> v[i];
    std::vector<std::priority_queue<std::pair<int,int>,
            std::vector<std::pair<int,int> >,
            std::greater<std::pair<int,int> > > > q(n + 1);
    for(int a,b,c,d,i = 1;i <= m;i++) {
        std::cin >> a >> b >> c >> d;
        while(!q[b].empty() && q[b].top().first <= a)
            cnt[b] -= q[b].top().second,q[b].pop();
        if(cnt[b] + d <= v[b]) {
            cnt[b] += d;
            q[b].push({a + c,d});
            std::cout << v[b] - cnt[b] << '\n';
        }
        else std::cout << -1 << '\n';
    }
    return 0;
}