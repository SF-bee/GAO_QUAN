#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;
const int mod = 998244353;

int n,tot;
ll a[MAX],cnt[MAX],res[MAX],ans = 1;
std::vector<int> book;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],book.push_back(a[i]);
    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++)
        a[i] = std::lower_bound(book.begin(),book.end(),a[i]) - book.begin();
    for(int mina = a[1],i = 2;i <= n;i++){
        if(a[i] > mina){
            if(cnt[a[i]] == 0){
                ans = (ans * 2) % mod;
                cnt[a[i]] = 1;
            }
            else if(cnt[a[i]] == 1)
                ans = (ans + res[a[i]]) % mod;
        }
        else if(a[i] < mina)
            mina = a[i];
    }
    std::cout << ans << '\n';
    return 0;
}