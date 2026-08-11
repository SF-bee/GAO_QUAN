#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;

int Tc;
std::string S, T;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> Tc;
    while (Tc--) {
        ll ans = 0;
        std::cin >> S >> T;
        for (int i = 0; i < S.size(); i++) {
            int res = 0;
            for (int p = i, q = 0; p < S.size() && q < T.size();) {
                if (S[p] == T[q])
                    p++, q++, res++;
                else
                    q++;
            }
            ans += res;
        }
        std::cout << ans << '\n';
    }
    return 0;
}