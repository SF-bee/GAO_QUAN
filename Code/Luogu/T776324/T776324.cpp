#include <bits/stdc++.h>

int dream(int x, int y, int z);

std::vector<bool> solve(int n) {
    std::vector<bool> ans(n);
    if (n == 4) {
        int cnt[4];
        cnt[0] = dream(1, 2, 3);
        cnt[1] = dream(0, 2, 3);
        cnt[2] = dream(0, 1, 3);
        cnt[3] = dream(0, 1, 2);
        int sum = (cnt[0] + cnt[1] + cnt[2] + cnt[3]) / 3;
        ans[0] = sum - cnt[0];
        ans[1] = sum - cnt[1];
        ans[2] = sum - cnt[2];
        ans[3] = sum - cnt[3];
    } else if (n == 810000) {
        auto sub = solve(4);
        for (int i = 0; i < 4; i++)
            ans[i] = sub[i];
        int z = ans[0];
        std::vector<std::pair<int, int>> ls;
        for (int i = 4; i + 2 < n; i += 3) {
            int r = dream(i, i + 1, i + 2);
            if (r == 0) ans[i] = ans[i + 1] = ans[i + 2] = 0;
            else if (r == 3)
                ans[i] = ans[i + 1] = ans[i + 2] = 1;
            else if (r == 2) {
                int rr = dream(0, i, i + 1) - z;
                if (rr == 2) ans[i] = ans[i + 1] = 1, ans[i + 2] = 0;
                else
                    ans[i + 2] = 1, ls.emplace_back(i, i + 1);
            } else if (r == 1) {
                int rr = dream(0, i, i + 1) - z;
                if (rr == 0) ans[i] = ans[i + 1] = 0, ans[i + 2] = 1;
                else
                    ans[i + 2] = 0, ls.emplace_back(i, i + 1);
            }
        }
        while (ls.size() > 1) {
            auto [a, b] = ls.back();
            ls.pop_back();
            auto [c, d] = ls.back();
            ls.pop_back();
            int r = dream(a, c, 0) - z;
            if (r == 0) ans[a] = ans[c] = 0, ans[b] = ans[d] = 1;
            else if (r == 2)
                ans[a] = ans[c] = 1, ans[b] = ans[d] = 0;
            else {
                int rr = dream(0, 1, a) - ans[0] - ans[1];
                ans[a] = rr;
                if (rr == 1) {
                    ans[b] = ans[c] = 0;
                    ans[d] = 1;
                } else if (rr == 0) {
                    ans[b] = ans[c] = 1;
                    ans[d] = 0;
                }
            }
        }
        if (ls.size() != 0) {
            auto [a, b] = ls.back();
            ans[a] = dream(0, 1, a) - ans[0] - ans[1];
            ans[b] = 1 - ans[a];
        }
        for (int i = n - (n - 4) % 3; i < n; i++) {
            ans[i] = dream(0, 1, i) - ans[0] - ans[1];
        }
    }
    return ans;
}