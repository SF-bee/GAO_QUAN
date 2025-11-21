#include <bits/stdc++.h>

int n,m;
std::queue<int> que;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        que.push(i);
    for(int cnt = 1;!que.empty();cnt++){
        if(cnt == m){
            std::cout << que.front() << ' ';
            que.pop();
            cnt = 0;
        }
        else{
            que.push(que.front());
            que.pop();
        }
    }
    return 0;
}