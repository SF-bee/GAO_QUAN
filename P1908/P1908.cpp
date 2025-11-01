// #include <bits/stdc++.h>

// const int MAX = 500005;
// int n;
// int a[MAX],t[MAX];
// long long ans = 0;

// void merge(int l,int r){
//     if(l == r) return;
//     int mid = (l + r) >> 1;
//     merge(l,mid);merge(mid + 1,r);
//     for(int i = l,j = l,k = mid + 1;i <= r;i++){
//         if(j == mid + 1)
//             t[i] = a[k++];
//         else if(k == r + 1){
//             t[i] = a[j++];
//             ans += k - mid - 1;
//         }
//         else if(a[j] <= a[k]){
//             t[i] = a[j++];
//             ans += k - mid - 1;
//         }
//         else
//             t[i] = a[k++];
//     }
//     for(int i = l;i <= r;i++)
//         a[i] = t[i];
// }

// int main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> n;
    
//     for(int i = 0;i < n;i++) std::cin >> a[i];
//     merge(0,n - 1);
//     std::cout << ans << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 5e5 + 5;

ll n,ans,a[MAX];
std::vector<ll> book;
struct bit{
    ll c[MAX];
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

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i],book.push_back(a[i]);
    std::sort(book.begin(),book.end());
    book.erase(std::unique(book.begin(),book.end()),book.end());
    for(int i = 1;i <= n;i++) a[i] = std::lower_bound(book.begin(),book.end(),a[i]) - book.begin() + 1;

    for(int i = 1;i <= n;i++){
        sum.add(a[i],1);
        ans += sum.query(a[i] + 1,n);
    }
    std::cout << ans << '\n';
    return 0;
}