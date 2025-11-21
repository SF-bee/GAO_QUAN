#include <bits/stdc++.h>
using namespace std;
int l,m;
int vis[10005];
int main(){
    cin >> l >> m;
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        for(int j = u;j <= v;j++){
            vis[j]++;
        }
    }
    int sum = 0;
    for(int i = 0;i <= l;i++) if(vis[i] > 0) sum++;
    cout << l - sum + 1;
    return 0;
}