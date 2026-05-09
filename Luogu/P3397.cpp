#include <bits/stdc++.h>

const int MAX = 1145;
int n,m;
int a[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int x1,y1,x2,y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] += 1;
        a[x2 + 1][y2 + 1] += 1;
        a[x1][y2 + 1] -= 1;
        a[x2 + 1][y1] -= 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            std::cout << a[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}