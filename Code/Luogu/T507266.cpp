#include <bits/stdc++.h>
const int MAX = 8e3 + 5;

struct node {
    int u,v,w;
    bool operator<(const node &rhs) const {return w < rhs.w;}
};

int n,m,ans;
std::array<int,MAX> fa;
std::vector<node> edge;

node rd() {node e; std::cin >> e.u >> e.v >> e.w; return e;}
void init() {
    for(int i = 1;i <= n;i++)
        fa[i] = i;
}
int find(int x) {
    return fa[x] == x ? x :
            fa[x] = find(fa[x]);
}
void merge(int x,int y) {
    fa[find(x)] = find(y);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    init();
    edge.resize(m);
    std::generate_n(edge.begin(),m,rd);

    std::cout << n - 1 << ' ';
    std::sort(edge.begin(),edge.begin() + m);
    for(auto [u,v,w] : edge) {
        if(n <= 1) break;
        if(find(u) != find(v)) {
            merge(u,v);
            ans = w;
            n--;
        }
    }
    
    std::cout << ans;
    return 0;
}