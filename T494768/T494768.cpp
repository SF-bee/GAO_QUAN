#include <bits/stdc++.h>

std::array<std::array<int,5>,5> a;  //记录按钮情况
std::queue<std::pair<std::array<std::array<int,5>,5>,int> > que;
std::set<long long> vis;  //记录每种情况的编号

long long getnum(std::array<std::array<int,5>,5> x){  //用于求出每种情况的编号
    long long cnt = 0;
    for(int i = 1;i <= 3;i++)
        for(int j = 1;j <= 3;j++)
            cnt = cnt * 10 + (x[i][j] == 0 ? 1 : 2);
    return cnt;
}

bool check(std::array<std::array<int,5>,5> x){  //校验是否全部为1
    for(int i = 1;i <= 3;i++)
        for(int j = 1;j <= 3;j++)
            if(!x[i][j]) return false;
    return true;
}

int bfs(std::array<std::array<int,5>,5> x){  //搜索
    que.push({x,0});
    vis.insert(getnum(que.front().first));
    while(!que.empty()){
        auto [t,d] = que.front();
        que.pop();
        if(check(t)) return d;
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++){
                //更改按钮状态
                t[i][j] = (t[i][j] == 1 ? 0 : 1);
                t[i - 1][j] = (t[i - 1][j] == 1 ? 0 : 1);
                t[i + 1][j] = (t[i + 1][j] == 1 ? 0 : 1);
                t[i][j - 1] = (t[i][j - 1] == 1 ? 0 : 1);
                t[i][j + 1] = (t[i][j + 1] == 1 ? 0 : 1);
                long long x = getnum(t);
                if(vis.count(x) == 0){  //如果这种情况没出现过
                    vis.insert(x);  //记录
                    que.push({t,d + 1});
                }
                //回溯
                t[i][j] = (t[i][j] == 1 ? 0 : 1);
                t[i - 1][j] = (t[i - 1][j] == 1 ? 0 : 1);
                t[i + 1][j] = (t[i + 1][j] == 1 ? 0 : 1);
                t[i][j - 1] = (t[i][j - 1] == 1 ? 0 : 1);
                t[i][j + 1] = (t[i][j + 1] == 1 ? 0 : 1);
            }
        }
    }
    return -1;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 1;i <= 3;i++){
        for(int j = 1;j <= 3;j++){
            std::cin >> a[i][j];
        }
    }
    std::cout << bfs(a);
    return 0;
}