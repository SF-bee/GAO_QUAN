#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

long long n,ans;
long long a[MAX],sum[21][MAX]; //sum_k_i表示第1~i个数中第k位为1的数的个数

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int i = 1;i <= n;i++)
        for(int k = 0;k < 20;k++){
            if(1 << k & a[i]) sum[k][i] = 1;
        }
    for(int k = 0;k < 20;k++){
        long long cnt = 0;
        //求该位至少包含一个1的区间个数
        for(int r = 1,l = 1,c = 0;r <= n;r++){
            c += sum[k][r];
            if(c >= 1){
                while(c >= 1){
                    cnt += n - r + 1;
                    c -= sum[k][l];
                    l++;
                }
            }
        }
        ans += (2 << k) * cnt;
    }
    std::cout << ans / 2;
    return 0;
}
/*
input:
111 101 100
1：111 / 101 / 100 = 111，101，100
2：111 101 / 101 100 = 111，101
3：111 101 100 = 111
output:
35

2^2 : 6 10

*/