#include <bits/stdc++.h>
const size_t MAX = 1e8 + 5;

std::bitset<MAX> not_pri;
std::vector<int> pri;

void init(){
    for(int i = 2;i < MAX;i++){
        if(!not_pri[i]) pri.push_back(i);
        for(auto j : pri){
            if(i * j > MAX) break;
            not_pri[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}
void get(int x){
    int cnt = 0,flag = 0;
    for(int i = 0;x != 1 && pri[i] <= x;i++){
        int sum = 0;
        if(x % pri[i] == 0){
            cnt++;
            while(x % pri[i] == 0) x /= pri[i],sum++;
            if(cnt == 1 && sum > 1){
                std::cout << pri[i] << ' ';
                flag++;
                cnt++;
            }
            if(cnt == 2){
                if(flag == 0) std::cout << pri[i] << ' ' << pri[i] << '\n';
                else std::cout << pri[i] << '\n';
                flag = 2;
                return;
            }
        }
    }
    // if(flag == 1 && x != 1) std::cout << x << '\n';
    // else if(flag == 1) std::cout << -1 << '\n';
    // else std::cout << -1 << ' ' << -1 << '\n';
}

int T,n;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    init();
    std::cin >> T;
    while(T--){
        std::cin >> n;
        get(n);
    }
    return 0;
}