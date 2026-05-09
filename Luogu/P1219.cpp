#include <bits/stdc++.h>

const int MAX = 100;
int n,ans;
int v_h[MAX];
bool v_l[MAX],v_zx[MAX],v_yx[MAX];

void dfs(int i){
    if(i == n + 1){
        ans++;
        if(ans <= 3){
            for(int i = 1;i <= n;i++)
                std::cout << v_h[i] << ' ';
            std::cout << '\n';
        }
        return;
    }
    for(int j = 1;j <= n;j++){
        if(!v_l[j] && !v_zx[i + j] && !v_yx[i - j + n]){
            v_h[i] = j;
            v_l[j] = 1;
            v_zx[i + j] = 1;
            v_yx[i - j + n] = 1;
            dfs(i + 1);
            v_l[j] = 0;
            v_zx[i + j] = 0;
            v_yx[i - j + n] = 0;
        }
    }
}

int main(){
    std::cin >> n;
    dfs(1);
    std::cout << ans;
    return 0;
}