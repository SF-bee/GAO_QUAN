#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m,ans[MAX];
std::pair<int,int> lst[MAX],q[MAX],e[MAX];
std::vector<int> ga[MAX],gc[MAX];
bool era[MAX],vis[MAX];
struct Mset{
	int fa[MAX];
	void init(){for(int i = 1;i <= n;i++) fa[i] = i;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int x,int y) {
		if(find(x) != find(y))
			fa[find(x)] = find(y);
	}
}MGS;
//树剖
int fa[MAX],dep[MAX],son[MAX],siz[MAX],top[MAX];
//直径
int _dep[MAX];

int main(){
	std::cin.tie(0) -> sync_with_stdio(0);
	
	std::cin >> n >> m;
	for(int i = 1;i < n;i++)
		std::cin >> e[i].first >> e[i].second;
	for(int op,x,i = 1;i <= m;i++){
		std::cin >> op >> x;
		q[i] = {op,x};
		if(op == 1) era[x] = 1;
	}
	for(int i = 1;i < n;i++){
		ga[e[i].first].push_back(e[i].second),
		ga[e[i].second].push_back(e[i].first);
		if(!era[i])
			gc[e[i].first].push_back(e[i].second),
			gc[e[i].second].push_back(e[i].first);
	}

	//重链剖分
	auto dfs1 = [&](auto &dfs,int u,int f,int d) ->void
	{
		fa[u] = f;
		dep[u] = d;
		siz[u] = 1;
		for(auto v : ga[u]) if(v != f){
			dfs(dfs,v,u,d + 1);
			siz[u] += siz[v];
			if(siz[v] > siz[son[u]]) son[u] = v;
		}
	};
	auto dfs2 = [&](auto &dfs,int u,int tp) -> void
	{
		top[u] = tp;
		if(son[u]) dfs(dfs,son[u],tp);
		for(auto v : ga[u]) if(v != son[u] && v != fa[u])
			dfs(dfs,v,v);
	};
	dfs1(dfs1,1,1,1);
	dfs2(dfs2,1,1);
	auto LCA = [&](int x,int y) -> int
	{
		while(top[x] != top[y]){
			if (dep[top[x]] > dep[top[y]])
      			x = fa[top[x]];
    		else
      			y = fa[top[y]];
		}
		return dep[x] > dep[y] ? y : x;
	};
	auto dist = [&](int x,int y) {return dep[x] + dep[y] - 2 * dep[LCA(x,y)];};
	//求每个联通块的直径
	MGS.init();
	int c;
	auto flg = [&](auto &dfs,int u,int f,int d) -> void
	{
		vis[u] = 1;
		_dep[u] = d;
		for(auto v : gc[u]) if(v != f){
			MGS.merge(u,v);
			dfs(dfs,v,u,d + 1);
			if(_dep[c] < _dep[v]) c = v;
		}
	};
	for(int i = 1;i <= n;i++)
		if(!vis[i]){
			c = i;
			flg(flg,i,i,1);
			int l = c;
			flg(flg,l,l,1);
			lst[MGS.find(i)] = {l,c};
		}
	//处理询问
	for(int i = m;i >= 1;i--){
		auto [op,x] = q[i];
		if(op == 1){  //连接
			auto [u,v] = e[x];
			int l1 = lst[MGS.find(u)].first,r1 = lst[MGS.find(u)].second;
			int l2 = lst[MGS.find(v)].first,r2 = lst[MGS.find(v)].second;
			int len1 = dist(l1,r1);
			int len2 = dist(l1,l2);
			int len3 = dist(l1,r2);
			int len4 = dist(r1,l2);
			int len5 = dist(r1,r2);
			int len6 = dist(l2,r2);
			int nl,nr,mdis = std::max({len1,len2,len3,len4,len5,len6});
			if(mdis == len1) nl = l1,nr = r1;
			else if(mdis == len2) nl = l1,nr = l2;
			else if(mdis == len3) nl = l1,nr = r2;
			else if(mdis == len4) nl = r1,nr = l2;
			else if(mdis == len5) nl = r1,nr = r2;
			else nl = l2,nr = r2;
			MGS.merge(u,v);
			lst[MGS.find(v)] = {nl,nr};
		}
		else
			ans[i] =
			  std::max(dist(x,lst[MGS.find(x)].first),dist(x,lst[MGS.find(x)].second));
	}
	for(int i = 1;i <= m;i++)
		if(q[i].first == 2) std::cout << ans[i] << '\n';
	return 0;
}