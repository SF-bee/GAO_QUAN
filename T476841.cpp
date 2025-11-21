#include <bits/stdc++.h>

const int MAX = 20;
int n,m,q,len;
std::vector<int> vec;

int get(int x){
    int len = 0;
    while(x != 0){x/=10;len++;}
    return len;
}

int change(int x){
    int end = x % 10;
    x /= 10;
    end = (end * end) % 10;
    if(end == 0) len--;
    else x = end * pow(10,len - 1) + x;
    return x;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> q;
    len = get(n);
    for(int i = 0;i < q;i++){
        n = change(n);
        vec.push_back(n);
        if(n == m){
            for(auto i : vec) std::cout << i << '\n';
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}