#include <bits/stdc++.h>
using namespace std;
const int N = 200;
long long n, dp[N];
int p[47] = {0,   2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
             53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127,
             131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
int main() {
    dp[0] = 1;
    for (int i = 1; i <= 46; i++) {
        for (int j = p[i]; j <= 200; j++) {
            dp[j] += dp[j - p[i]];
        }
    }
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}