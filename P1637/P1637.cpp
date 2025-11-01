#include <bits/stdc++.h>
typedef long long ll;
const int N = 3e4 + 5;

int n;
ll a[N],dp[N][4];
std::vector<ll> book;

struct bit{
    ll c[N];
    #define lowbit(x) (x&(-x))
    void add(int x,int k){
        for(;x <= n;x += lowbit(x))
            c[x] += k;
    }
    int query(int x){
        ll res = 0;
        while(x > 0){
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
    #undef lowbit
}tree;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],dp[i][1] = 1,book.push_back(a[i]);
    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++) a[i] = std::lower_bound(book.begin(),book.end(),a[i]) - book.begin() + 1;
    for(int i = 2;i <= 3;i++){
        memset(tree.c,0,sizeof(tree.c));
        for(int j = 1;j <= n;j++){
            dp[j][i] = tree.query(a[j] - 1);
            tree.add(a[j],dp[j][i - 1]);
        }
    }
    ll sum = 0;
    for(int i = 1;i <= n;i++)
        sum += dp[i][3];
    std::cout << sum << '\n';
    return 0;
}