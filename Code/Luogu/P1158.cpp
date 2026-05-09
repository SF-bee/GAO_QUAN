#include <bits/stdc++.h>

const int MAX = 100005;
struct node{
    int s1,s2;
}a[MAX];
int x_1,y_1,x_2,y_2;
int n;

bool comp(node x,node y){
    return x.s1 < y.s1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> x_1 >> y_1 >> x_2 >> y_2;
    std::cin >> n;
    for(int i = 0;i < n;i++){
        int x,y;
        std::cin >> x >> y;
        a[i].s1 = pow(x_1 - x,2) + pow(y_1 - y,2);
        a[i].s2 = pow(x_2 - x,2) + pow(y_2 - y,2);
    }
    std::sort(a,a + n,comp);
    for(int i = n - 2;i >= 0;i--){
        a[i].s2 = std::max(a[i].s2,a[i + 1].s2);
    }
    int mina = INT_MAX;
    for(int i = 0;i < n;i++){
        mina = std::min(mina,a[i].s1 + a[i + 1].s2);
    }
    std::cout << mina;
    return 0;
}