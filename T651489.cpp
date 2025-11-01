#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;

struct task{
    ll a,b;
    bool operator < (const task &rhs) const{
        return a + b < rhs.a + rhs.b;
    }
}t[MAX];
ll n;
std::vector<int> u,v;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> t[i].a;
    for(int i = 1;i <= n;i++)
        std::cin >> t[i].b;
    std::sort(t + 1,t + n + 1);
    ll ans = 0;
    std::priority_queue<ll> que;
    for(ll cnt = 0,i = 1;i <= n;i++){
        if(que.empty()) que.push(t[i].b),cnt += t[i].b,ans++;
        else{
            if(cnt <= t[i].a){
                que.push(t[i].b);
                cnt += t[i].b;
                ans++;
            }
            else if(cnt > t[i].a){
                if(t[i].b < que.top()){
                    cnt -= que.top();
                    que.pop();
                    que.push(t[i].b);
                    cnt += t[i].b;
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}