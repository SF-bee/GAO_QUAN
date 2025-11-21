#include <bits/stdc++.h>

const int MAX = 1e2+5;
int n,m,ans;
std::array<int,MAX> arr[MAX];

inline int sum(int i,int j,int k,int l) {return arr[k][l] - arr[i - 1][l] - arr[k][j - 1] + arr[i - 1][j - 1];}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            std::cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            // std::cout << arr[i][j] << " \n"[j == m];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = i;k <= n;k++){
                for(int l = j;l <= m;l++){
                    if(k - i != l - j) continue;
                    // std::cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << sum(i,j,k,l) << '\n';
                    if(sum(i,j,k,l) == (k - i + 1) * (k - i + 1)){
                        ans = std::max(ans,k - i + 1);
                    }
                }
            }
        }
    }

    std::cout << ans;
    return 0;
}