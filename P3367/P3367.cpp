#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m;
int fa[MAX],siz[MAX];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

void merge(int x,int y){
    int tx = find(x),ty = find(y);
    if(siz[tx] > siz[ty]) std::swap(tx,ty);
    siz[ty] += siz[ty],fa[tx] = ty;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) fa[i] = i,siz[i] = 1;

    int z,x,y;
    while(m--){
        std::cin >> z >> x >> y;
        switch(z){
            case 1:
                merge(x,y);
                break;
            case 2:
                std::cout << (find(x) == find(y) ? "Y\n" : "N\n");
                break;
        }
    }
    return 0;
}