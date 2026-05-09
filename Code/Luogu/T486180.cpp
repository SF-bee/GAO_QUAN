#include <bits/stdc++.h>

const int MAX = 1e6 + 5;
int n,ans,mx = -INT_MAX,mi = INT_MAX;
std::array<int,MAX> arr;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        int x,y;
        std::cin >> x >> y;
        mi = std::min(mi,x);
        mx = std::max(mx,y);
        arr[x] += 1;
        arr[y + 1] -= 1;
    }

    for(int i = mi;i <= mx;i++){
        arr[i] += arr[i - 1];
        ans = std::max(ans,arr[i]);
    }

    std::cout << ans;
    return 0;
}