#include <bits/stdc++.h>

const int MAX = 7000;
struct edge{  //边
    int u,v,w;
    bool operator<(const edge &rhs) const {return w < rhs.w;}
}e[MAX];
int t,n,ans;
struct uf{   //并查集
    std::vector<int> fa,size,mx;   //fa_i为i的代表元，size为当前连通块的大小，mx为当前连通块边的最大值
    uf(int sz) :   //构造一个大小为sz的并查集并初始化
    fa(sz),size(sz,1),mx(sz,0){
        //std::iota可递增填充一个容器
        std::iota(fa.begin(), fa.end(), 0);
    }
    //查找元素
    int find(int x) {return (fa[x] == x ? x : fa[x] = find(fa[x]));}
    //启发式合并
    void merge(int x,int y,int i) {
        x = find(x),y = find(y);
        if(size[x] < size[y]) std::swap(x,y);
        ans += (size[x] * size[y] - 1) * ((mx[x] = std::max({mx[x],mx[y],e[i].w})) + 1);
        fa[y] = x;
        size[x] += size[y];
    }
};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> t;
    while(t--){
        ans = 0;
        std::cin >> n;
        uf pa(n + 1);
        for(int i = 1;i < n;i++)
            std::cin >> e[i].u >> e[i].v >> e[i].w;
        std::sort(e,e + n);
        for(int i = 1;i < n;i++){
            pa.merge(e[i].u,e[i].v,i);
        }
        std::cout << ans << '\n';
    }
    return 0;
}