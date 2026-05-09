#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,m,ans;
std::array<long long,MAX> r,d,s,t;
std::array<long long,MAX> sum;

inline long long rd(){long long x; std::cin >> x; return x;}

bool check(int mid){
    memset(sum.begin(),0,sizeof(sum));
    for(int i = 1;i <= mid;i++){
        sum[s[i]] += d[i],
        sum[t[i] + 1] -= d[i];
    }
    for(int i = 1;i <= n;i++){
        sum[i] += sum[i - 1];
        if(sum[i] > r[i])
            return 0;
    }
    return 1;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    std::generate_n(r.begin() + 1,n,rd);
    for(int i = 1;i <= m;i++){
        std::cin >> d[i] >> s[i] >> t[i];
    }
    if(check(m)){
        std::cout << 0;
        return 0;
    }
    for(int l = 1,r = m,mid;l <= r;){
        mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = (ans = mid) - 1;
    }
    std::cout << -1 << '\n' << ans;
    return 0;
}