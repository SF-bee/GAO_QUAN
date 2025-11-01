#include <bits/stdc++.h>

const int MAX = 5e5 + 5;
int n,m;
int arr[MAX],c[MAX];

int lowbit(int x) {return x & (-x);}

int pre[MAX];
void init(){
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + arr[i];
        c[i] = pre[i] - pre[i - lowbit(i)];
    }
}

int sum(int x){
    int res = 0;
    for(int i = x;i != 0;i -= lowbit(i)) res += c[i];
    return res;
}

void add(int x,int y){
    for(int i = x;i <= n;i += lowbit(i)) c[i] += y;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> arr[i];
    init();
    
    while(m--){
        int op,x,y;
        std::cin >> op >> x >> y;
        switch (op){
            case 1: add(x,y); break;
            default: std::cout << sum(y) - sum(x - 1) << '\n'; break;
        }
    }
    return 0;
}