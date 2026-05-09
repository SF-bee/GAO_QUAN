#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int T,n;
bool s1[MAX],s2[MAX],t1[MAX],t2[MAX];
int cnt1,cnt2,g1[MAX],g2[MAX];
int c1[MAX][2],c2[MAX][2];

int main(){
    freopen("edit2.in","r",stdin);
    freopen("edit2.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> T;
    while(T--){
        int ans = 0;
        char ch;
        std::memset(c1,0,sizeof(c1));
        std::memset(c2,0,sizeof(c2));
        t1[0] = t2[0] = -1;
        cnt1 = cnt2 = 0;
        std::cin >> n;
        for(int i = 1;i <= n;i++)
            std::cin >> ch,s1[i] = ch - '0';
        for(int i = 1;i <= n;i++)
            std::cin >> ch,s2[i] = ch - '0';
        for(int i = 1;i <= n;i++) {
            std::cin >> ch,t1[i] = ch - '0';
            if(t1[i] != t1[i - 1]) ++cnt1;
            g1[i] = cnt1;
            c1[cnt1][s1[i]]++;
        }
        for(int i = 1;i <= n;i++) {
            std::cin >> ch,t2[i] = ch - '0';
            if(t2[i] != t2[i - 1]) ++cnt2;
            g2[i] = cnt2;
            c2[cnt2][s2[i]]++;
        }
        for(int i = 1;i <= n;i++) {
            if(c1[g1[i]][0] && c2[g2[i]][0]) ans++,c1[g1[i]][0]--,c2[g2[i]][0]--;
            else if(c1[g1[i]][1] && c2[g2[i]][1]) ans++,c1[g1[i]][1]--,c2[g2[i]][1]--;
            else if(c1[g1[i]][1]) c1[g1[i]][1]--,c2[g2[i]][0]--;
            else c1[g1[i]][0]--,c2[g2[i]][1]--;

        }
        std::cout << ans << '\n';
    }
    return 0;
}