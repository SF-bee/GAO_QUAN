#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

double n, k;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    double ans = 0, b = 1;
    while (n) {
        if (n - (k / b) >= 0) { // 假如剩余路程大于一段
            n = n - (k / b);
            ans += k;
        } else { // 不够一段
            ans += n * b;
            n = 0;
        }
        b += 2;
    }
    std::cout << (long long)ceil(ans) << '\n';
    return 0;
}
/*
n = 30,k = 10
到达n=n，我需要在n=n处留下0个苹果，我一车可以走10，我可以在n=20处取货，倍率1
到达n=20,我需要在n=20处留下10个苹果，我一车可以走3.333，我可以在16.666处取货，倍率3
到达n=16.666，我需要在16.666处留下20个，我一车可以走
*/