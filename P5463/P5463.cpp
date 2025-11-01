#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e6 + 5;

ll n,maxa,a[MAX];
__int128 ans;
std::vector<ll> book;
struct bit{
    __int128 c[MAX];
    #define lowbit(x) (x&(-x))
    void add(ll x,ll k){
        for(;x <= n;x += lowbit(x))
            c[x] += k;
    }
    ll query(ll x){
        ll res = 0;
        while(x > 0){
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
    ll query(ll x,ll y){
        return query(y) - query(x - 1);
    }
    #undef lowbit
}sum;

void write(__int128 x){
    if(x > 9) write(x / 10);
    std::cout << char(x % 10 + '0');
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i],book.push_back(a[i]);
    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++){
        a[i] = std::lower_bound(book.begin(),book.end(),a[i]) - book.begin() + 1;
        maxa = std::max(maxa,a[i]);
    }

    for(int i = 1;i <= n;i++){
        sum.add(a[i],i);
        ans += sum.query(a[i] + 1,maxa) * (n - i + 1);
    }
    write(ans);
    return 0;
}