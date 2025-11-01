#include <bits/stdc++.h>
const int MAX = 1e5 + 1e3;


std::pair<int,int> ans[MAX];

int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans.out","w",stdout);
    for(int i = 1;i <= 2000;i++)
        std::cin >> ans[i].first >> ans[i].second;
    for(int i = 1;i <= 1500;i++){
        std::cout << ans[i].first << ' ' << ans[i].second << '|' << ans[i + 104].first << ' ' << ans[i + 104].second << '\n';
    }
    return 0;
}