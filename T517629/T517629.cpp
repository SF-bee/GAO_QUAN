#include <bits/stdc++.h>
typedef long long ll;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll n;
    std::cin >> n;
    //发现斐波那契数列每 3 个为一个偶数。
    //每个奇数贡献前面偶数的个数。
    //每个偶数贡献前面数的个数
    //有 n/3 个偶数，n-n/3 个奇数。
    //分别等差数列求和。
    ll even = (2+2+3*(n/3-1))*(n/3)/2; //偶数贡献
    ll odd;
    if(n % 3 == 0)
        odd = ((n-n/3) % 2 == 0 ? (n/3-1)*(n-n/3)/2 : (n/3)*(n-n/3 + 1)/2 - n/3); //奇数贡献,分类讨论奇个奇数和偶个奇数
    else
        odd = ((n-n/3) % 2 == 0 ? (n/3)*(n-n/3)/2 : (n/3)*(n-n/3 + 1)/2 - n/3);
    std::cout << even + odd  << '\n';
    return 0;
}
/*
id  1  2  3  4  5  6  7   8   9
num 1  1  2  3  5  8  13  21  34
con 0  0  2  1  1  5  2   2   8
*/