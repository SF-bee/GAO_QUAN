#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n;
std::array<int,MAX> a;

inline int rd(){int x;std::cin >> x;return x;}

int dfs(int l,int r){
    if(l == r) return 1;
    int cnt = INT_MAX;
    for(int i = l;i <= r;i++)
        if(a[i] != 0) cnt = std::min(cnt,a[i]);
    for(int i = l;i <= r;i++)
        a[i] -= cnt;
    for(int i = l,j;i <= r;i++){
        if(a[i] != 0){
            for(j = i;a[j] != 0;j++);
            cnt += dfs(i,j - 1);
            i = j - 1;
        }
    }
    return std::min(cnt,r - l + 1);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    std::generate_n(a.begin() + 1,n,rd);

    std::cout << dfs(1,n);
    return 0;
}