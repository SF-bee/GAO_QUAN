#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n,m;
ll p[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int l,r,i = 1;i <= m;i++){
        if(i == 1) std::cin >> l;
        else{
            std::cin >> r;
            p[std::min(l,r)] += 1;
            p[std::max(l,r)] -= 1;
            l = r;
        }
    }
    for(int i = 1;i < n;i++) p[i] += p[i - 1];
    ll a,b,c,ans = 0;
    for(int i = 1;i < n;i++)
        std::cin >> a >> b >> c, ans += std::min(a * p[i],b * p[i] + c);
    std::cout << ans << '\n';
    return 0;

}