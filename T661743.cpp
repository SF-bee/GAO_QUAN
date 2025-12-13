#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,q,r[MAX],a[MAX];
std::pair<int,int> b[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    int op3 = 0;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],b[i - 1] = {a[i],i};
    std::sort(b,b + n);
    for(int i = 0;i < n;i++)
        r[b[i].second] = i;
    while(q--){
        int op,u,v;
        std::cin >> op >> u;
        switch (op){
            case 1:
                if(r[u] == 0) std::cout << "N0\n";
                else std::cout << r[u] << '\n';
                break;
            case 2:
                std::cin >> v;
                if(u == v || r[u] < r[v]) std::cout << "N0\n";
                else std::cout << 1 << '\n';
                break;
            case 3:
                std::cin >> v;
                if(op3 < 5){
                    op3++;
                    a[u] = v;
                    for(int i = 1;i <= n;i++)
                        b[i - 1] = {a[i],i};
                    std::sort(b,b + n);
                    for(int i = 0;i < n;i++)
                        r[b[i].second] = i;
                }
                
                break;
        }
    }
    return 0;
}