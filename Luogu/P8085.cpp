#include <bits/stdc++.h>
const int MAX = 1e6;
const unsigned long long base = 13331;

int n = 1,m = 1;
std::string s;
std::unordered_map<std::string,int> vis;
int num1[MAX],cnt1[MAX],num2[MAX],cnt2[MAX];
unsigned long long hs1,pw[MAX],hs2;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    while(std::cin >> s && s != "$"){
        if(vis[s] == 0) num1[n] = 0;
        else num1[n] = n - vis[s],cnt1[vis[s]] = n;
        vis[s] = n++;
    }n--;
    vis.clear();
    while(std::cin >> s && s != "$"){
        if(vis[s] == 0) num2[m] = 0;
        else num2[m] = m - vis[s],cnt2[vis[s]] = m;
        vis[s] = m++;
    }m--;
    pw[0] = 1;
    for(int i = 1;i <= m;i++){
        hs1 = hs1 * base + num1[i];
        hs2 = hs2 * base + num2[i];
        pw[i] = pw[i - 1] * base;
    }
    if(hs1 == hs2) {std::cout << 1 << '\n';return 0;}
    // for(int i = m + 1;i <= n;i++) std::cout << num1[i - m] * pw[m] << ' ';
    // std::cout << '\n';
    for(int i = m + 1;i <= n;i++){
        hs1 = hs1 * base + num1[i], hs1 = hs1 - num1[i - m] * pw[m];
        // std::cout << num1[i - m] * pw[m] << ' ';
        if(cnt1[i - m] <= i){
            // num1[cnt1[i - m]] = 0;
            hs1 -= num1[i - m] * pw[i - cnt1[i - m]];
        }else num1[cnt1[i - m]] = 0;
        // std::cout << hs1 << ' ' << hs2 << '\n';
        if(hs1 == hs2) {std::cout << i - m + 1 << '\n'; return 0;}
    }
    return 0;
}
/*
0 1 1 0 0 0 4 4 4
*/