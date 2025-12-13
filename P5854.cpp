#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e7 + 5;

struct node{
    int ls,rs;
    int key,val;
    node(){
        key = val = ls = rs = 0;
    }
    node(int KEY,int VAL) : key(KEY),val(VAL){
        ls = rs = 0;
    }
};
node tre[MAX];
int st[MAX],k,top;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for(int i = 1;i <= n;i++)
        std::cin >> p[i],tre[i] = node(i,p[i]);
    for(int i = 1;i <= n;i++){
        int k = top;
        while (k > 0 && p[st[k]] > p[i]) k--;
        if (k) tre[st[k]].rs = i;
        if (k < top) tre[i].ls = st[k + 1];
        st[++k] = i;
        top = k;
    }
    ll xl = 0,xr = 0;
    for(int i = 1;i <= n;i++)
        xl ^= 1ll * i * (tre[i].ls + 1),
        xr ^= 1ll * i * (tre[i].rs + 1);
    std::cout << xl << ' ' << xr << '\n';
    return 0;
}