#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

int n,m;
char a[MAX][MAX];
int h[MAX][MAX],l[MAX][MAX],r[MAX][MAX];
int L[MAX][MAX],R[MAX][MAX];

int main(){
    freopen("P4147_8.in","r",stdin);
    std::memset(R,0x3f,sizeof(R));
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> a[i][j];
    for(int i = 1;i <= n;i++){
        int t = 0;
        for(int j = 1;j <= m;j++){
            if(a[i][j] == 'F')
                h[i][j] = h[i - 1][j] + 1,
                l[i][j] = t;
            else
                l[i][j] = 0,t = j;
        }
        t = m + 1;
        for(int j = m;j >= 1;j--){
            if(a[i][j] == 'F')
                r[i][j] = t;
            else
                r[i][j] = m + 1,t = j;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) if(a[i][j] == 'F'){
            L[i][j] = std::max(l[i][j] + 1,L[i - 1][j]);
            R[i][j] = std::min(r[i][j] - 1,R[i - 1][j]);
            ans = std::max(ans,(R[i][j] - L[i][j] + 1) * h[i][j]);
        }
        else L[i][j] = l[i][j] + 1,R[i][j] = r[i][j] - 1;
    }
    std::cout << ans * 3 << '\n';
    return 0;
}