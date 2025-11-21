#include <bits/stdc++.h>

int n,ans;

void dfs(int x,int y){  //x为入栈队列长度，y为当前栈长度
    if(x == 0) {ans++;return;}
    if(y > 0) dfs(x,y - 1);
    dfs(x - 1,y + 1);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    dfs(n,0);
    std::cout << ans;
    return 0;
}