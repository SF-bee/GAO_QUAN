#include <bits/stdc++.h>

const int MAX = 1e5 + 5;
int n;
std::queue<int> mes;

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
                mes.push(x);
                break;
            case 2:
                if(!mes.empty()) mes.pop();
                else std::cout << "ERR_CANNOT_POP\n";
                break;
            case 3:
                if(!mes.empty()) std::cout << mes.front() << '\n';
                else std::cout << "ERR_CANNOT_QUERY\n";
                break;
            case 4:
                std::cout << mes.size() << '\n';
                break;
        }
    }
    return 0;
}