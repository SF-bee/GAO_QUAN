#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int T;
int n, a[MAX];

void sol() {
    std::cin >> n;
    std::vector<int> event;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], event.push_back(a[i]);

    std::sort(event.begin(), event.end());
    event.erase(std::unique(event.begin(), event.end()), event.end());
    for (int i = 1; i <= n; i++) {
        int rnk = std::lower_bound(event.begin(), event.end(), a[i]) - event.begin() + 1;
        std::cout << rnk << " \n"[i == n];
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--)
        sol();
    return 0;
}