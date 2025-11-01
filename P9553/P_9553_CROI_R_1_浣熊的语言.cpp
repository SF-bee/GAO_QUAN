#include <bits/stdc++.h>

const int MAX = 1e6 + 5;
int n,m,k,ans;
std::array<int,MAX> d,s,t;
std::array<int,MAX> cnt_new,cnt_old;

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n >> m >> k;
    std::generate_n(d.begin() + 1,n,rd);
    std::generate_n(s.begin() + 1,m,rd);
    std::generate_n(t.begin() + 1,k,rd);

    for(int i = 1;i <= n;i++)
        cnt_new[d[i]]++,ans = std::max(ans,d[i]);
    for(int i = 1;i <= m;i++){
        cnt_new[s[i] + 1] += cnt_new[s[i]];
        cnt_new[s[i]] = 0;
    }
    for(int i = 1;i <= d[n];i++){
        if(cnt_new[i] != 0){
            for(int j = 1;j <= k;j++){
                ans = std::max(ans,i + t[j]);
                cnt_old[i + t[j]] += cnt_new[i];
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cnt_old[s[i] + 1] += cnt_old[s[i]];
        cnt_new[s[i] + 1] += cnt_new[s[i]];
        cnt_old[s[i]] = cnt_new[s[i]] = 0;
    }
    std::cout << ans << '\n';
    for(int i = 1;i <= ans;i++)
        std::cout << cnt_new[i] << ' ' << cnt_old[i] << '\n';
    return 0;
}