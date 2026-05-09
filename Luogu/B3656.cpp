#include <bits/stdc++.h>
typedef long long ll;

const int MAX = 1e6 + 5;
int q;
std::map<std::string,int> mp;
std::map<int,std::list<int>> deq;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    mp["push_back"] = 1;
    mp["pop_back"] = 2;
    mp["push_front"] = 3;
    mp["pop_front"] = 4;
    mp["size"] = 5;
    mp["front"] = 6;
    mp["back"] = 7;

    std::cin >> q;
    while(q--){
        std::string op;
        int a,x;
        std::cin >> op >> a;
        switch (mp[op]){
            case 1:
                std::cin >> x;
                deq[a].push_back(x);
                break;
            case 2:
                if(!deq[a].empty()) deq[a].pop_back();
                break;
            case 3:
                std::cin >> x;
                deq[a].push_front(x);
                break;
            case 4:
                if(!deq[a].empty()) deq[a].pop_front();
                break;
            case 5:
                std::cout << deq[a].size() << '\n';
                break;
            case 6:
                if(!deq[a].empty()) std::cout << deq[a].front() << '\n';
                break;
            case 7:
                if(!deq[a].empty()) std::cout << deq[a].back() << '\n';
        }
    }
    return 0;
}