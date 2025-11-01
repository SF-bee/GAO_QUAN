#include <bits/stdc++.h>
const int MAX = 4e4;

int n,m;
int v[MAX],p[MAX],dp[MAX];  //v为花费，p为重要度，dp_j表示背包大小为j时的答案最大值
std::vector<int> ma;  //存储主件
std::vector<int> q[MAX];  //存储对应主件的附件

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int id;
        std::cin >> v[i] >> p[i] >> id;
        if(id != 0) q[id].push_back(i);
        else ma.push_back(i);
    }

    for(auto i : ma){
        for(int j = n;j >= 0;j--){
            //四种情况：只买主件，买主+A,买主+B,买主+AB
            if(j >= v[i])  //只买主件
                dp[j] = std::max(dp[j],dp[j - v[i]] + v[i] * p[i]);
            if(q[i].size() == 1 && j >= v[i] + v[q[i][0]])  //只有一个附件
                dp[j] = std::max(dp[j],dp[j - v[i] - v[q[i][0]]] + v[i] * p[i] + v[q[i][0]] * p[q[i][0]]);
            if(q[i].size() == 2){
                if(j >= v[i] + v[q[i][0]]) //买主+A
                    dp[j] = std::max(dp[j],dp[j - v[i] - v[q[i][0]]] + v[i] * p[i] + v[q[i][0]] * p[q[i][0]]);
                if(j >= v[i] + v[q[i][1]]) //买主+B
                    dp[j] = std::max(dp[j],dp[j - v[i] - v[q[i][1]]] + v[i] * p[i] + v[q[i][1]] * p[q[i][1]]);
                if(j >= v[i] + v[q[i][0]] + v[q[i][1]]) //买主+AB
                    dp[j] = std::max(dp[j],dp[j - v[i] - v[q[i][0]] - v[q[i][1]]] + v[i] * p[i] + v[q[i][0]] * p[q[i][0]] + v[q[i][1]] * p[q[i][1]]);
            }
        }
    }
    std::cout << dp[n] << '\n';
    return 0;
}