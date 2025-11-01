#include <bits/stdc++.h>

int n;
std::stack<int> s1;
std::multiset<int> s;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    while(n--){
        int op,x;
        std::cin >> op;
        switch (op){
            case 1:
                std::cin >> x;
                s1.push(x);
                s.insert(x);
                break;
            case 2:
                if(s1.empty()){
                    std::cout << "ERROR\n";
                    return 0;
                }
                std::cout << s1.top() << '\n';
                s.erase(s.lower_bound(s1.top()));
                s1.pop();
                break;
            case 3:
                std::cout << *s.begin() << '\n';
                break;
        }
    }
    return 0;
}