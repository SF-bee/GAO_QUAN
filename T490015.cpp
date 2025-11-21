#include <bits/stdc++.h>
const int MAX = 1e5+5;

int n,m;
std::bitset<MAX> A,B;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < n;i++){
        int x;
        std::cin >> x;
        A[x] = 1;
    }
    for(int i = 0;i < m;i++){
        int x;
        std::cin >> x;
        B[x] = 1;
    }
    std::cout << (A & B).count() << ' ';
    std::cout << (A | B).count() << ' ';
    std::cout << (A ^ (A & B)).count() << '\n';
    return 0;
}