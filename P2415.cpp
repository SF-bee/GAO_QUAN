#include <bits/stdc++.h>

int main(){
    int a[100];
    long long sum = 0;
    int i = 0;
    while(std::cin >> a[i]){sum += a[i++];}
    std::cout << sum * pow(2,i - 1);
    return 0;
}