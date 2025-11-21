#include <bits/stdc++.h>

int ans;
std::vector<int> a,d,f;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    while(std::cin >> t)
        a.push_back(t);
    for(auto i : a){
        //最长不上升子序列
        if(d.size() == 0) d.push_back(i);
        else if(i <= *(d.end() - 1)) d.push_back(i);
        else d[std::lower_bound(d.begin(),d.end(),i,std::greater<int>()) - d.begin()] = i;
        //最长上升子序列
        if(f.size() == 0) f.push_back(i);
        else if(i > *(f.end() - 1)) f.push_back(i);
        else f[std::lower_bound(f.begin(),f.end(),i) - f.begin()] = i;
    }
    std::cout << d.size() << '\n' << f.size() << '\n';
    return 0;
}