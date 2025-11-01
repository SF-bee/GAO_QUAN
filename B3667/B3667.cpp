#include <bits/stdc++.h>
typedef unsigned long long ull;
const int MAX = 1e6 + 5;

int n,k;
std::deque<int> que;
ull a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    for(int i = 1;i <= n - k + 1;i++){
        if(i == 1){
            for(int j = 1;j <= k;j++){
                while(!que.empty() && a[que.back()] <= a[j])
                    que.pop_back();
                que.push_back(j);
            }
        }
        else{
            while(!que.empty() && a[que.back()] <= a[i + k - 1])
                que.pop_back();
            que.push_back(i + k - 1);
        }
        std::cout << que.size() << '\n';
        if(que.front() == i) que.pop_front();
    }
    return 0;
}