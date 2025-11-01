#include <bits/stdc++.h>

const int MAX = 2e3 + 5;
int n;
long long ans = -LONG_LONG_MAX;
std::array<long long, MAX> a[MAX];

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 0;i < n;i++)
        std::generate_n(a[i].begin(),n,rd);
    
    //横线
    for(int i = 0;i < n;i++){
        long long cnt = 0;
        for(int j = 0;j < n;j++)
            cnt += a[i].at(j);
        ans = std::max(ans,cnt);
    }
    //竖向
    for(int j = 0;j < n;j++){
        long long cnt = 0;
        for(int i = 0;i < n;i++)
            cnt += a[i].at(j);
        ans = std::max(ans,cnt);
    }

    //右到左斜线
    for(int i = 0;i <= 2 * (n - 1);i++){
        long long cnt = 0;
        for(int j = 0;j < n;j++){
            if(0 <= i - j && i - j < n) cnt += a[i - j].at(j);
        }
        ans = std::max(ans,cnt);
    }

    //左到右斜线
    for(int i = 1-n;i <= n - 1;i++){
        long long cnt = 0;
        for(int j = 0;j < n;j++){
            if(0 <= i + j && i + j < n) cnt += a[i + j].at(j);
        }
        ans = std::max(ans,cnt);
    }
    
    std::cout << ans;
    return 0;
}
/*
  0 1 2 3 4    0 1 2 3 4
0 0 1 2 3 4  0 0-1-2-3-4         
1 1 2 3 4 5  1 1 0-1-2-3        
2 2 3 4 5 6  2           
3 3 4 5 6 7  3           
4 4 5 6 7 8  4           
*/