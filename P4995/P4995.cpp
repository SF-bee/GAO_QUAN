#include <bits/stdc++.h>

const int MAX = 1000;
int n;
int h[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> h[i];
    std::sort(h + 1,h + n + 1);
    int l = 1,r = n;
    long long sum = 0;
    bool flag = 1;
    while(l < r){
        sum += pow(h[l] - h[r],2);
        if(flag){
            r--;
            flag = !flag;
        }
        else{
            l++;
            flag = !flag;
        }
    }
    std::cout << sum + h[n] * h[n];
    return 0;
}
/*
1 1 1 1 1 1 1
*/