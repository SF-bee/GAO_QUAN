#include <bits/stdc++.h>
const int MAX = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n,x;
int h[MAX],sum[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> x;
    for(int i = 1;i < n;i++)
        std::cin >> h[i],sum[i] = sum[i - 1] + h[i];
    
    auto check = [&](int mid) -> bool {
        for(int i = 1;i + mid - 1 < n;i++)
            if(sum[i + mid - 1] - sum[i - 1] < 2 * x) return false;
        return true;
    };
    int ans,l = 1,r = n;
    for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1) {
        if(check(mid)) r = (ans = mid) - 1;
        else l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}