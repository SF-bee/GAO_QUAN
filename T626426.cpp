#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

long long n,a[MAX],c[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i];

    for(int i = 1;1+(i-1)*i/2 <= n;i++){ //枚举长度
        for(int j = 1;j <= i;j++){ //枚举子序列中的第几个
            //首个可以作为第j项：1+(j-1)*j/2
            //最后一个可以作为第j项：1+(j-1)*j/2+(n-(1+(i-1)*i/2))
            if(j % 2 == 1){
                c[1+(j-1)*j/2] += 1;
                c[1+(j-1)*j/2+(n-(1+(i-1)*i/2)) + 1] -= 1;
            }
            else{
                c[1+(j-1)*j/2] -= 1;
                c[1+(j-1)*j/2+(n-(1+(i-1)*i/2)) + 1] += 1;
            }
        }
    }
    for(int i = 1;i <= n;i++)
        c[i] += c[i - 1];
    long long sum = 0;
    for(int i = 1;i <= n;i++)
        sum += a[i] * c[i];
    std::cout << sum << '\n';
    return 0;
}