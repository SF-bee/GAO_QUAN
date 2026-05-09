#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

int n,k;
int mx,my,cnt[MAX][MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> k;
    for(int x1,y1,x2,y2,i = 1;i <= n;i++){
        std::cin >> x1 >> y1 >> x2 >> y2;
        mx = std::max(mx,x2);
        my = std::max(my,y2);
        cnt[x1 + 1][y1 + 1] ++;
        cnt[x1 + 1][y2 + 1] --;
        cnt[x2 + 1][y1 + 1] --;
        cnt[x2 + 1][y2 + 1] ++;
    }
    int ans = 0;
    for(int i = 1;i < MAX;i++)
        for(int j = 1;j < MAX;j++){
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            ans += 1 * (cnt[i][j] == k);
        }
    std::cout << ans << '\n';
    return 0;
}