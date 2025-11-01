#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

struct node{
    int i,j,e;
    bool operator < (const node &rhs) const{return e > rhs.e;}
};
int t,n,fa[MAX],siz[MAX];
node a[MAX];
std::vector<int> num;

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

void merge(int x,int y){
    int tx = find(x),ty = find(y);
    if(siz[tx] < siz[ty]) std::swap(tx,ty);
    siz[tx] += siz[ty],fa[ty] = tx;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> t;
    while (t--){
        bool flag = true;
        std::cin >> n;
        for(int i = 0;i <= n;i++) fa[i] = i,siz[i] = 1; 
        num.clear();
        for(int i = 1;i <= n;i++){
            std::cin >> a[i].i >> a[i].j >> a[i].e;
            num.push_back(a[i].i),num.push_back(a[i].j);
        }
        std::sort(num.begin(),num.end());
        num.erase(std::unique(num.begin(),num.end()),num.end());
        for(int i = 1;i <= n;i++){
            a[i].i = std::lower_bound(num.begin(),num.end(),a[i].i) - num.begin();
            a[i].j = std::lower_bound(num.begin(),num.end(),a[i].j) - num.begin();
        }
        std::sort(a + 1,a + n + 1);
        for(int i = 1;i <= n;i++){
            // std::cout << a[i].e << ' ';
            if(a[i].e == 1) merge(a[i].i,a[i].j);
            else if(find(a[i].i) == find(a[i].j)){
                std::cout << "NO\n";
                flag = false;
                break;
            }
        }
        std::cout << (flag ? "YES\n" : "");
    }
    return 0;
}