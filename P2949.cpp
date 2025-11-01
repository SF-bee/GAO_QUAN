#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n;
ll ans;
std::pair<ll,ll> t[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> t[i].first >> t[i].second;
    std::sort(t + 1,t + n + 1);
    std::priority_queue<ll> que;
    for(int i = 1;i <= n;i++){
        //可以直接做
        if(que.size() < t[i].first){
            que.push(-t[i].second);
            ans += t[i].second;
        }
        //不能做，舍弃贡献最少的任务
        else{
            if(-que.top() < t[i].second){
                ans += t[i].second + que.top();
                que.pop();
                que.push(-t[i].second);                
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}