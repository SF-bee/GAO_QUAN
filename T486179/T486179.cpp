#include <bits/stdc++.h>

int n,m,ans;
std::string a,b;

bool check(int mid){
    for(int i = 0,j = 0;i < mid;i++){ //枚举前缀
        bool flag = 0;
        for(;j < m;j++){ //查找子序列
            if(b[j] == a[i]) {flag = 1; j++; break;}
        }
        if(!flag) return 0;
    }
    return 1;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    std::cin >> a;
    std::cin >> b;
    for(int l = 0,r = n,mid;l <= r;){ //二分最长前缀
        mid = (l + r) >> 1;
        if(check(mid)) l = (ans = mid) + 1;
        else r = mid - 1;
    }
    std::cout << ans;
    return 0;
}