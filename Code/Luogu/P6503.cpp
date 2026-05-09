/*
原式等价于
所有元素分别乘作为最大值次数的和 - 所有元素分别乘作为最小值次数的和

问题变为：求每个元素作为区间最大/小值的次数
*/
#include <bits/stdc++.h>
using ll = long long;
const int MAX = 3e5 + 5;

int n;
ll a[MAX],cmax[MAX],cmin[MAX];
ll maxl,maxr;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];

    
    return 0;
}