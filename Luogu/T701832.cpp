#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,k;
int a[MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    
    std::deque<int> que1,que2;
    std::vector<int> maxa,mina;
    for(int i = 1;i <= k;i++){
        while (!que1.empty() && a[que1.back()] < a[i]) que1.pop_back();
        while (!que2.empty() && a[que2.back()] > a[i]) que2.pop_back();
        que1.push_back(i);
        que2.push_back(i);
    }
    maxa.push_back(que1.front());
    mina.push_back(que2.front());
    for(int i = k + 1;i <= n;i++){
        while(!que1.empty() && que1.front() <= i - k) que1.pop_front();
        while(!que2.empty() && que2.front() <= i - k) que2.pop_front();
        while (!que1.empty() && a[que1.back()] < a[i]) que1.pop_back();
        while (!que2.empty() && a[que2.back()] > a[i]) que2.pop_back();
        que1.push_back(i);
        que2.push_back(i);
        maxa.push_back(que1.front());
        mina.push_back(que2.front());
    }
    for(auto i : mina)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    for(auto i : maxa)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}