#include <bits/stdc++.h>
const int MAX = 1e2 + 5;
const int N = 2e5 + 5;

int n;
int a[MAX];
std::bitset<N> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    int S = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], S += a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp |= (dp << a[i]);
    if (S & 1) std::cout << "0\n";
    else if (dp[S / 2] == 0)
        std::cout << "0\n";
    else {
        while (true) {
            for (int i = 1; i <= n; i++) {
                if (a[i] % 2) {
                    std::cout << 1 << '\n' << i << '\n';
                    return 0;
                }
                a[i] /= 2;
            }
        }
    }
    return 0;
}
/*
判断数组好不好是容易的
01背包秒了
然后呢？可以考虑一下可以划分的结构？
如果数组总和是奇的，必然不能被划分，也就是说，如果有奇数，删掉这个奇数就不能划分了
那如果没有奇的？
那就全是偶的，全是偶的那 /2 依然是可以划分的
这时候如果有奇的，那不就可以再除了，这时候那个奇的就是需要删掉的数字
*/