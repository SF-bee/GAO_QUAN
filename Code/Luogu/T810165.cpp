#include <bits/stdc++.h>
const int MAX = 5e6 + 5;

int w, z, Q;
bool NotPrime[MAX];
int cnt[MAX], ckPrime[MAX];
bool check(int num) {
    while (num) {
        if (num % 10 == z) return 1;
        num /= 10;
    }
    return 0;
}
void init() {
    std::vector<int> prime;
    for (int i = 2; i < MAX; i++) {
        if (!NotPrime[i]) {
            prime.push_back(i);
            ckPrime[i] = 1;
            cnt[i] = check(i);
        }
        for (int p : prime) {
            if (i * p >= MAX) break;
            NotPrime[i * p] = 1;
            if (i % p != 0) {
                cnt[i * p] = check(p) ? cnt[i] + 1 : cnt[i];
                if (cnt[i * p] >= w) ckPrime[i * p] = 1;
            }
            if (i % p == 0) {
                cnt[i * p] = cnt[i];
                if (cnt[i * p] >= w) ckPrime[i * p] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < MAX; i++)
        ckPrime[i] += ckPrime[i - 1];
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> w >> z >> Q;
    init();
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << ckPrime[r] - ckPrime[l - 1] << '\n';
    }
    return 0;
}
/*
考虑在线性筛的同时分解质因数
那么可以注意到一个事情：
千秋质数存在某种转移关系：意思是说，如果一个数x是千秋质数，那么x*p也是千秋质数
启示我们可以记忆化搜索,可以在判断一个数是不是千秋质数的同时把路径上的也一起判断了
*/