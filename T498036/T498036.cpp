#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;

int n;
std::array<ll,MAX> a,b,ta,tb;

ll merge(int l,int r){  //归并排序
    if(l == r) return 0;
    int mid = (l + r) >> 1;
    ll cnt = merge(l,mid) + merge(mid + 1,r);
    //处理每个右区间的雷达能扫到左区间雷达的数量
    for(int i = mid + 1;i <= r;i++){
        auto pl = std::lower_bound(a.begin() + l,a.begin() + mid + 1,a[i] - b[i]);
        auto pr = std::upper_bound(a.begin() + l,a.begin() + mid + 1,a[i] + b[i]) - 1;
        cnt += pr - pl + 1;
    }
    //归并
    for(int i = l,j = l,k = mid + 1;i <= r;i++){  //i代表合并后的位置，j代表左区间的下标，k代表右区间的下标
        if(j == mid + 1)
            ta[i] = a[k],
            tb[i] = b[k++];
        else if(k == r + 1)
            ta[i] = a[j],
            tb[i] = b[j++];
        else{
            if(a[j] < a[k])
                ta[i] = a[j],
                tb[i] = b[j++];
            else
                ta[i] = a[k],
                tb[i] = b[k++];
        }
    }
    for(int i = l;i <= r;i++)
        a[i] = ta[i],b[i] = tb[i];
    return cnt;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int i = 1;i <= n;i++)
        std::cin >> b[i];
    
    std::cout << merge(1,n) << '\n';
    return 0;
}