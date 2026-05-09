#include <bits/stdc++.h>
const int MAX = 5e2 + 5;

struct edge{
    int x,y,w;
    bool operator<(const edge &rhs) const {return w < rhs.w;}
};
int a,b,ans,pa[MAX],mp[MAX][MAX];
std::vector<edge> e;

int find(int x) {return (pa[x] == x ? x : pa[x] = find(pa[x]));}
void unite(int x,int y) {pa[find(x)] = find(y);}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> a >> b;
    for(int x,i = 1;i <= b;i++){
        pa[i] = i;
        for(int j = 1;j <= b;j++) {
            std::cin >> x;
            mp[i][j] = x;
        }
    }
    for(int i = 1;i <= b;i++)
        for(int j = 1;j <= b;j++)
            if(i <= j && mp[i][j] != 0) e.push_back({i,j,mp[i][j]});
    for(int i = 1;i <= b;i++)
        e.push_back({0,i,a});
    std::sort(e.begin(),e.end());
    for(int i = 0;i < e.size();i++){
        auto [u,v,w] = e[i];
        if(find(u) != find(v)){
            ans += w;
            unite(u,v);
        }
    }
    std::cout << ans << '\n';
    return 0;
}