#include <bits/stdc++.h>

const int MAX = 100;
int s[5],a[MAX];
int l,r,mina;
int ans;

void dfs(int d,int y){
    if(d > y){
        mina = std::min(mina,std::max(l,r));
        return;
    }
    l += a[d];
    dfs(d + 1,y);
    l -= a[d];
    r += a[d];
    dfs(d + 1,y);
    r -= a[d];
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> s[1] >> s[2] >> s[3] >> s[4];
    
    for(int i = 1;i <= 4;i++){
        l = r = 0;
        mina = INT_MAX;
        memset(a,0,sizeof(a));
        for(int j = 1;j <= s[i];j++) std::cin >> a[j];
        dfs(1,s[i]);
        ans += mina;
    }
    std::cout << ans;
    return 0;
}