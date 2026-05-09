#include <bits/stdc++.h>
const int MAX = 1e5 + 1e3;

int T,s;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
std::pair<int,int> ans[MAX];
std::map<std::pair<int,int>,bool> mp;

int main(){
    // freopen("ans.txt","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    mp[{0,0}] = 0;
    ans[0] = {0,0};
    for(int x = 0,y = 0,d = 0,i = 1;i <= 11104;i++){
        if(mp[{x,y}]){  //黑格
            mp[{x,y}] = 0;
            d = (d - 1 + 4) % 4;
            x += dx[d],y += dy[d];
            ans[i] = {x,y};
            if(mp.count({x,y}) == 0) mp[{x,y}] = 0;
        }
        else{
            mp[{x,y}] = 1;
            d = (d + 1 + 4) % 4;
            x += dx[d],y += dy[d];
            ans[i] = {x,y};
            if(mp.count({x,y}) == 0) mp[{x,y}] = 0;
        }
    }
    std::cin >> T;
    while(T--){
        std::cin >> s;
        if(s <= 11104) std::cout << ans[s].first << ' ' << ans[s].second << '\n';
        else{
            int k = (s - 11000) / 104,r = (s - 11000) % 104;
            int x = ans[11000 + r].first,y = ans[11000 + r].second;
            std::cout << x - 2 * k << ' ' << y - 2 * k << '\n';
        }
    }
    return 0;
}