#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int T;
int n;
int a[3][MAX];
std::vector<int> club[3];

void solve(){
    std::memset(a,0,sizeof(a));
    club[0].clear(),club[1].clear(),club[2].clear();

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> a[0][i] >> a[1][i] >> a[2][i];
        if(a[0][i] == std::max({a[0][i],a[1][i],a[2][i]}))
            club[0].push_back(i);
        else if(a[1][i] == std::max({a[0][i],a[1][i],a[2][i]}))
            club[1].push_back(i);
        else
            club[2].push_back(i);
    }
    int sum = 0,max_club = std::max({club[0].size(),club[1].size(),club[2].size()});
    if(max_club > n / 2) {
        auto comp = [&](const int &i,const int &j) -> bool {
            int ti[] = {a[0][i],a[1][i],a[2][i]};
            int tj[] = {a[0][j],a[1][j],a[2][j]};
            std::sort(ti,ti + 3);
            std::sort(tj,tj + 3);
            return ti[2] - ti[1] > tj[2] - tj[1];
        };
        if(club[0].size() == max_club) {
            std::sort(club[0].begin(),club[0].end(),comp);
            while(club[0].size() > n / 2) {
                if(a[1][club[0].back()] > a[2][club[0].back()])
                    club[1].push_back(club[0].back());
                else
                    club[2].push_back(club[0].back());
                club[0].pop_back();
            }
        }
        else if(club[1].size() == max_club) {
            std::sort(club[1].begin(),club[1].end(),comp);
            while(club[1].size() > n / 2) {
                if(a[0][club[1].back()] > a[2][club[1].back()])
                    club[0].push_back(club[1].back());
                else
                    club[2].push_back(club[1].back());
                club[1].pop_back();
            }
        }
        else {
            std::sort(club[2].begin(),club[2].end(),comp);
            while(club[2].size() > n / 2) {
                if(a[0][club[2].back()] > a[1][club[2].back()])
                    club[0].push_back(club[2].back());
                else
                    club[1].push_back(club[2].back());
                club[2].pop_back();
            }
        }
    }
    for(auto i : club[0]) sum += a[0][i];
    for(auto i : club[1]) sum += a[1][i];
    for(auto i : club[2]) sum += a[2][i];
    std::cout << sum << '\n';
    return;
}

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);
    
    std::cin >> T;
    while(T--)
        solve();
    return 0;
}