#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m,E,T;
bool vis[MAX],can[MAX]; //存某个连通块是否合法 
int cnt[MAX],p[MAX],ans[MAX]; //cnt 某个连通块有多少个发电站 
std::vector<std::pair<int,int> > e;

struct mgs{
	int fa[MAX];
	void init(){
		for(int i = 1;i <= n + m;i++) {
			fa[i] = i;
			cnt[i] = (i <= n) ? 1 : 0;
			can[i] = (i > n);
		}
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int x,int y) {
		if(find(x) != find(y)){
			fa[find(y)] = fa[find(x)];
			cnt[find(x)] += cnt[find(y)];
			can[find(x)] |= can[find(y)];
		}
			
	}
}MGS;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m >> E;
    MGS.init();
    e.resize(E + 1);
    for(int i = 1;i <= E;i++)
        std::cin >> e[i].first >> e[i].second;
    std::cin >> T;
    for(int i = 1;i <= T;i++)
        std::cin >> p[i],vis[p[i]] = 1;
    
    for(int i = 1;i <= E;i++)
		if(!vis[i]) MGS.merge(e[i].first,e[i].second);
	int totalSafe = 0;
    for(int i = 1;i <= n;i++){
        int root = MGS.find(i);
        if(can[root]){
            totalSafe++;
        }
    }
    
    // 逆序处理
    ans[T] = totalSafe;
    for(int i = T;i >= 2;i--){
        int u = e[p[i]].first, v = e[p[i]].second;
        int fu = MGS.find(u), fv = MGS.find(v);
        
        if(fu == fv) {
            ans[i-1] = ans[i];
            continue;
        }
        bool uHasFactory = can[fu];
        bool vHasFactory = can[fv];
        int uCnt = cnt[fu];
        int vCnt = cnt[fv];
        MGS.merge(u, v);
        
        if(!uHasFactory && vHasFactory) {
            totalSafe += uCnt;
        } else if(uHasFactory && !vHasFactory) {
            totalSafe += vCnt;
        }
        
        ans[i-1] = totalSafe;
    } 
	for(int i = 1;i <= T;i++)
		std::cout << ans[i] << '\n';
    return 0;
}
