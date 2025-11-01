#include <bits/stdc++.h>
const int MAX = 3e5 + 5;

namespace io{
    void read(int &x) {
        bool neg = false;
        x = 0;
        char ch = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') neg = true;
                ch = getchar();
        }
        if (neg) {
            while (ch >= '0' && ch <= '9') {
            x = x * 10 + ('0' - ch);
            ch = getchar();
        }
        } else {
            while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
            }
        }
    }
void write(int x) {
  bool neg = false;
  if (x < 0) {
    neg = true;
    putchar('-');
  }
  static int sta[40];
  int top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  } while (x);
  if (neg)
    while (top) putchar('0' - sta[--top]);
  else
    while (top) putchar('0' + sta[--top]);
}
}

struct edge{
    int to,dis;
};
struct node{
    int u,v,w,lca;
    bool operator<(const node &rhs) const{
        return w > rhs.w;
    }
}edg[MAX];
int n,m,maxa,l,r,sub,ans;
int cnt[MAX],w[MAX],siz[MAX],fa[MAX],son[MAX],top[MAX],dep[MAX],len[MAX];
std::vector<edge> g[MAX];

//第一次深搜，预处理深度，子树大小，重儿子，父亲
void dfs1(int u,int f,int d){
    dep[u] = d;
    siz[u] = 1;
    son[u] = -1;
    fa[u] = f;
    for(auto [to,dis] : g[u]) if(to != f){
        w[to] = dis;
        len[to] += len[u] + dis;
        dfs1(to,u,d + 1);
        siz[u] += siz[to];
        if(son[u] == -1 || siz[son[u]] < siz[to]) son[u] = to;
    }
}
//第二次深搜，标记重链
void dfs2(int u,int t){
    top[u] = t;
    if(son[u] == -1) return;
    dfs2(son[u],t);
    for(auto [to,dis] : g[u]) if(to != fa[u] && to != son[u])
        dfs2(to,to);
}
int lca(int x,int y){
    while(top[x] != top[y]){
        if(dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    return dep[x] > dep[y] ? y : x;
}
void pre(int u,int fa,int m){  
    for(auto [to,dis] : g[u]) if(to != fa){
        pre(to,u,m);
        cnt[u] += cnt[to];
    }
    if(cnt[u] == m && w[u] > w[sub]) sub = u;
}
bool check(int mid){ //二分判断
    std::memset(cnt,0,sizeof(cnt));
    int i = 1,maxa = -1;
    sub = 0;
    for(;i <= m;i++){
        if(edg[i].w <= mid) break;
        auto [u,v,w,lca] = edg[i];
        cnt[u] += 1;
        cnt[v] += 1;
        cnt[lca] -= 2;
        maxa = std::max(maxa,w);
    }
    pre(1,0,i - 1); //找路径交点，如果路径无交则对最小值没有影响
    return maxa - w[sub] <= mid;
}

int main(){
    io::read(n);
    io::read(m);
    for(int u,v,w,i = 1;i < n;i++){
        io::read(u);io::read(v);io::read(w);
        edg[i] = {u,v,w};
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        maxa = std::max(maxa,w);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    for(int u,v,i = 1;i <= m;i++){ //处理路径长度
        io::read(u),io::read(v);
        int l = lca(u,v);
        edg[i] = {u,v,len[u] + len[v] - 2 * len[l],l};
        r = std::max(r,edg[i].w);
    }
    std::sort(edg + 1,edg + m + 1); //以路径长度排序
    l = r - maxa;
    for(int mid = (l + r) / 2;l <= r;mid = (l + r) / 2){
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    io::write(ans);
    return 0;
}