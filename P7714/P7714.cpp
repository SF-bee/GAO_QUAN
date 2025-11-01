#include <bits/stdc++.h>

const int MAX = 1000005;
int a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        for(int i = 1;i <= n;i++) std::cin >> a[i];
        int i = 1,sum = 0;
        while(i <= n){
            if(a[i] == i) i++;
            else{
                int maxa = a[i];
                int j = i + 1;
                maxa = std::max(maxa,a[j]);
                while(maxa > j){
                    j++;
                    maxa = std::max(maxa,a[j]);
                }
                sum += j - i + 1;
                i = j + 1;
            }
        }
        std::cout << sum << '\n';
    }
    return 0;
}