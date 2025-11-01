#include <bits/stdc++.h>

const int MAXN = 1e5;
int T,n,q;
int l,r,ans;
int a[MAXN],nxt[MAXN],vis[14];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        memset(nxt,0,sizeof(nxt));
        memset(vis,0,sizeof(vis));
        std::cin >> n;
        for(int i = 1;i <= n;i++){
            std::cin >> a[i];
            if(vis[a[i]] == 0) vis[a[i]] = i;
            else nxt[vis[a[i]]] = i,vis[a[i]] = i;;
        }
        std::cin >> q;
        while(q--){
            ans = 0;
            std::cin >> l >> r;
            for(int i = l;i <= r;i++){
                if(nxt[i] == 0 || nxt[i] > r){
                    ans++;
                    continue;
                }
                else{
                    i = nxt[i];
                }
            }
            std::cout << ans << '\n';
        }
    }
    return 0;
}