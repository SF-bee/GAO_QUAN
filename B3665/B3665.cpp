#include <bits/stdc++.h>
#define int unsigned int
const int MAX = 3e6 + 5;

int n,q;
std::vector<int> a[MAX];

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int i = 1,s;i <= n;i++){
        std::cin >> s;
        a[i].resize(s + 1);
        for(int j = 1;j <= s;j++)
            std::cin >> a[i][j];
    }
    int sum = 0;
    while(q--){
        int x,y;
        std::cin >> x >> y;
        sum ^= a[x][y];
    }
    std::cout << sum;
    return 0;
}