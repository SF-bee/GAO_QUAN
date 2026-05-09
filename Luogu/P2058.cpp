#include <bits/stdc++.h>

struct node{
    int t;
    std::vector<int> x;
};

const int MAX = 1e5 + 5;
int n;   //船的数量
std::map<int,int> now;   //统计 24 小时内各个国籍的人数
std::queue<node> que;    //队列维护 24 小时内的船

inline int rd(){int x; std::cin >> x; now[x]++; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        int t,k;    //t表示到达时间，k表示人数
        std::vector<int> boat;    //boat_i表示第 i 个人的国籍
        std::cin >> t >> k;
        boat.resize(k);
        std::generate_n(boat.begin(),k,rd);
        if(t > 86400){    //超过 24 小时才开始判断
            while(!que.empty()){    //将超出 24 小时的船移除
                auto [lt,lboat] = que.front();
                if(t - 86400 < lt) break;
                que.pop();
                for(auto i : lboat){    //将对应船的人数减去
                    now[i]--;
                    if(now[i] == 0) now.erase(i);
                }
            }
        }
        que.push({t,boat});    //入队
        std::cout << now.size() << '\n';
    }
    return 0;
}