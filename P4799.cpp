#include <bits/stdc++.h>
const int MAX = 50;

long long n,m;
long long ans,a[MAX];
std::vector<long long> cnt;

void dfs(int l,int r,long long res,bool op){
    if(l > r){
        if(op == 0)
            cnt.push_back(res);
        else
            ans += std::upper_bound(cnt.begin(),cnt.end(),m - res) - cnt.begin();
    }
    else{
        //不选
        dfs(l + 1,r,res       ,op);
        //选
        dfs(l + 1,r,res + a[l],op);
    }
    
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < n;i++)
        std::cin >> a[i];
    int mid = n / 2;
    dfs(0,mid - 1,0,0);
    std::sort(cnt.begin(),cnt.end());
    dfs(mid,n - 1,0,1);
    std::cout << ans << '\n';
    return 0;
}