#include <bits/stdc++.h>

int n,m;
std::set<std::string> s;
std::set<std::string> vis;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::string t;
        std::cin >> t;
        s.insert(t);
    }
    std::cin >> m;
    while(m--){
        std::string t;
        std::cin >> t;
        if(s.count(t) && !vis.count(t)){
            std::cout << "OK\n";
            vis.insert(t);
        }
        else if(s.count(t) && vis.count(t)){
            std::cout << "REPEAT\n";
        }
        else if(!s.count(t)){
            std::cout << "WRONG\n";
        }
    }
    return 0;
}