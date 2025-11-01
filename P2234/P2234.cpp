#include <bits/stdc++.h>

const int MAX = 50000;
int n;
std::set<int> a;
int sum;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        int t;
        std::cin >> t;
        if(i == 0){
            a.insert(t);
            sum += t;
        }
        else{
            auto p = a.lower_bound(t);
            if(p != a.begin())
                sum += std::min(abs(*p - t),abs((*p--) - t));
            else
                sum += abs(*p - t);
            a.insert(t);
        }
    }
    std::cout << sum;
    return 0;
}