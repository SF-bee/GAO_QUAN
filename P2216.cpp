#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

int a,b,n;
int mit[MAX][MAX];
int max_a[MAX][MAX],max_b[MAX][MAX];
int min_a[MAX][MAX],min_b[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a >> b >> n;
    for(int i = 1;i <= a;i++)
        for(int j = 1;j <= b;j++)
            std::cin >> mit[i][j];
    for(int i = 1;i <= a;i++){
        std::deque<int> que,eup;
        for(int j = 1;j <= b;j++){
            while (!que.empty() && (j - que.front() + 1) > n) que.pop_front();
            while (!que.empty() && mit[i][que.back()] <= mit[i][j]) que.pop_back();
            que.push_back(j);
            if(j >= n)
                max_a[i][j - n + 1] = mit[i][que.front()];
            while (!eup.empty() && (j - eup.front() + 1) > n) eup.pop_front();
            while (!eup.empty() && mit[i][eup.back()] >= mit[i][j]) eup.pop_back();
            eup.push_back(j);
            if(j >= n)
                min_a[i][j - n + 1] = mit[i][eup.front()];
        }
    }
    for(int j = 1;j <= b - n + 1;j++){
        std::deque<int> que,eup;
        for(int i = 1;i <= a;i++){
            while (!que.empty() && (i - que.front() + 1) > n) que.pop_front();
            while (!que.empty() && max_a[que.back()][j] <= max_a[i][j]) que.pop_back();
            que.push_back(i);
            if(i >= n)
                max_b[i - n + 1][j] = max_a[que.front()][j];
            while (!eup.empty() && (i - eup.front() + 1) > n) eup.pop_front();
            while (!eup.empty() && min_a[eup.back()][j] >= min_a[i][j]) eup.pop_back();
            eup.push_back(i);
            if(i >= n)
                min_b[i - n + 1][j] = min_a[eup.front()][j];
        }
    }
    int ans = INT_MAX;
    for(int i = 1;i <= a - n + 1;i++)
        for(int j = 1;j <= b - n + 1;j++)
            ans = std::min(ans,max_b[i][j] - min_b[i][j]);
    std::cout << ans << '\n';
    return 0;
}