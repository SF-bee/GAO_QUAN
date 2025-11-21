#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,ans = 0,a[MAX];
std::vector<int> smin,smax;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int r = 1;r <= n;r++){
        while(!smin.empty() && a[smin.back()] >= a[r]) smin.pop_back();
        while(!smax.empty() && a[smax.back()] < a[r]) smax.pop_back();
        int x;
        if(smax.empty()) x = std::upper_bound(smin.begin(),smin.end(),0) - smin.begin();
        else x = std::upper_bound(smin.begin(),smin.end(),smax.back()) - smin.begin();
        if(smin.begin() + x != smin.end())
            ans = std::max(ans,r - smin[x] + 1);
        // for(auto i : smin) std::cout << i << ' ';
        // std::cout << '|';
        // for(auto i : smax) std::cout << i << ' ';
        // std::cout << '\n';
        smin.push_back(r);
        smax.push_back(r);
    }
    std::cout << ans << '\n';
    return 0;
}