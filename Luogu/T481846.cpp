#include <bits/stdc++.h>
typedef unsigned long long ull;

const int MAX = 1e5 + 5;
int T,n;
std::stack<ull> book;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> T;
    while(T--){
        while(!book.empty()) book.pop();
        std::cin >> n;
        while(n--){
            std::string op;
            ull x;
            std::cin >> op;
            if(op == "add"){
                std::cin >> x;
                book.push(x);
            }
            else if(op == "remove"){
                if(!book.empty()) book.pop();
                else std::cout << "Empty\n";
            }
            else if(op == "peek"){
                if(!book.empty()) std::cout << book.top() << '\n';
                else std::cout << "NoBook!\n";
            }
            else if(op == "count") std::cout << book.size() << '\n';
        }
    }
    return 0;
}