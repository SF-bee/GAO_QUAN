#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;

int n,k,r;
ll ans,a[MAX],dp[MAX];
struct cmp{
    bool operator()(const int &x, const int &y) const {
        return a[x] < a[y];
    }
};
std::set<ll,cmp> pre,pos;

int main(){
    #if !ONLINE_JUDGE
    freopen("seq_ex.in","r",stdin);
    freopen("seq_ex.out","w",stdout);
    #endif

    std::cin >> n >> k >> r;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int j = 1;j <= r;j++){
        if(j == 1) dp[j] = a[j];
        else dp[j] = dp[*(--pre.end())] + a[j];
        ans = std::max(ans,dp[j]);
        pre.insert(j);
    }
    while(pre.size() > r - 1) pos.insert(*(--pre.end())),pre.erase(--pre.end());
    for(int j = r + 1;j <= n;j++){
        dp[j] = dp[*pos.begin()] + a[j];
        ans = std::max(ans,dp[j]);
        if(pre.size() != 0 && a[j] > a[*(--pre.end())]) pos.insert(j);
        else {
            pre.insert(j);
            pos.insert(*(--pre.end()));
            pre.erase(--pre.end());
        }
        if(j - k >= 1){
            if(pre.find(j - k) != pre.end()){
                pre.erase(j - k);
                pre.insert(*pos.begin());
                pos.erase(pos.begin());
            }
            else pos.erase(j - k);
        }
        
    }
    std::cout << ans << '\n';
    return 0;
}