#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;

struct point{
    ll x, y;
}p[MAX];
ll n,q,nmax,sum[MAX * 3],l[MAX],r[MAX];
std::vector<ll> book;

int main(){
    #if !ONLINE_JUDGE
    freopen("seg_ex.in","r",stdin);
    freopen("seg_ex.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> p[i].x, book.push_back(p[i].x);
    for(int i = 1;i <= n;i++) std::cin >> p[i].y;
    std::cin >> q;
    for(int i = 1;i <= q;i++){
        std::cin >> l[i] >> r[i];
        book.push_back(l[i]);
        book.push_back(r[i]);
    }
    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++){
        p[i].x = std::lower_bound(book.begin(),book.end(),p[i].x) - book.begin() + 1;
        sum[p[i].x] += p[i].y;
    }
        
    for(int i = 1;i <= book.size();i++) sum[i] += sum[i - 1];
    for(int i = 1;i <= q;i++){
        int ql = std::lower_bound(book.begin(),book.end(),l[i]) - book.begin() + 1;
        int qr = std::lower_bound(book.begin(),book.end(),r[i]) - book.begin() + 1;
        std::cout << sum[qr] - sum[ql - 1] << '\n';
    }
    return 0;
}