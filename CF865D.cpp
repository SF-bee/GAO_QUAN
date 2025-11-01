#include <bits/stdc++.h>
const int MAX = 3e5 + 5;

long long n,ans,p[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::priority_queue<long long,std::vector<long long>,std::greater<long long> > que;
    for(int i = 1;i <= n;i++){
        std::cin >> p[i];
        que.push(p[i]),que.push(p[i]);
        ans += p[i] - que.top();
        que.pop();
    }
    std::cout << ans << '\n';
    return 0;
}