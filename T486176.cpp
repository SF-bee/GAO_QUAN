#include <bits/stdc++.h>
typedef long long lint;

const int MAX = 1e2 + 5;
int n,m,k,ans;
std::array<int,MAX> arr[MAX];
std::array<int,MAX> brr;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int x,y;
        std::cin >> x >> y;
        arr[x][y] = 1;
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int x = i;x <= n;x++)
                for(int y = j;y <= n;y++)
                    if(arr[x][y] - arr[i - 1][y] - arr[x][j - 1] + arr[i - 1][j - 1] >= k)
                        ans++;
    std::cout << ans;
    return 0;
}