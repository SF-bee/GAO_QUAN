#include <bits/stdc++.h>
const int MAX = 5050;

int l[MAX],h[MAX],r[MAX];
int b[2 * MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n = 1;
    while(std::cin >> l[n] >> h[n] >> r[n]){
        for(int i = l[n];i < r[n];i++) b[i] = std::max(b[i],h[n]);
        n++;
    }
    for(int i = 1;i <= 10000;i++)
        if(b[i] != b[i - 1]) std::cout << i << ' ' << b[i] << ' ';
    return 0;
}