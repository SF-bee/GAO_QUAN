#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

// Every edge is directed away from 1 in a valid candidate tree.
// Iterative heavy-light decomposition avoids recursion on a long chain.
struct Tree {
    int n, x = 0, y = 0;
    vector<int> parent, depth, size, heavy, top;
    ll plain = 0, visited = INF;
    Tree(const vector<int>& p, int a, int b) : n((int)p.size()-1), x(a), y(b),
        parent(p), depth(n+1), size(n+1,1), heavy(n+1), top(n+1) {}
    bool build() {
        vector<int> first(n+1,-1), next(n+1,-1), order;
        order.reserve(n);
        for (int v=2; v<=n; ++v) {
            if (!parent[v]) return false;
            next[v]=first[parent[v]]; first[parent[v]]=v;
        }
        order.push_back(1); top[1]=1;
        for (int i=0; i<(int)order.size(); ++i) {
            int u=order[i];
            for (int v=first[u]; v!=-1; v=next[v]) {
                depth[v]=depth[u]+1; order.push_back(v);
            }
        }
        if ((int)order.size()!=n) return false;
        for (int i=n-1; i>0; --i) {
            int v=order[i], u=parent[v];
            size[u]+=size[v];
            if (!heavy[u] || size[v]>size[heavy[u]]) heavy[u]=v;
        }
        for (int i=1; i<n; ++i) {
            int v=order[i], u=parent[v];
            top[v]=(heavy[u]==v ? top[u] : v);
        }
        if (y==1) visited=0;
        return true;
    }
    int distance(int u, int v) const {
        int result=depth[u]+depth[v];
        while (top[u]!=top[v]) {
            if (depth[top[u]]<depth[top[v]]) swap(u,v);
            u=parent[top[u]];
        }
        return result-2*min(depth[u],depth[v]);
    }
};

int main() {
    int n,m;
    if (scanf("%d%d",&n,&m)!=2) return 0;
    vector<int> from(m), to(m), first(n+1,-1), next(m), parent(n+1), seen(n+1);
    for (int i=0; i<m; ++i) {
        scanf("%d%d",&from[i],&to[i]);
        next[i]=first[from[i]]; first[from[i]]=i;
    }
    // A directed search supplies one arborescence and its sole omitted edge.
    vector<int> order(1,1), chosen(m);
    seen[1]=1;
    for (int i=0; i<(int)order.size(); ++i) {
        int u=order[i];
        for (int e=first[u]; e!=-1; e=next[e]) {
            int v=to[e];
            if (!seen[v]) {
                seen[v]=1; parent[v]=u; chosen[e]=1; order.push_back(v);
            }
        }
    }
    if (m==n-1) {
        Tree t(parent,0,0); t.build();
        ll answer=0;
        for (int v=2; v<=n; ++v) {
            answer+=t.distance(v-1,v);
            printf("%lld\n",answer);
        }
        return 0;
    }
    int extra=0;
    while (chosen[extra]) ++extra;
    int x=from[extra], y=to[extra];
    vector<Tree> trees;
    trees.reserve(2);
    trees.emplace_back(parent,x,y); trees.back().build();
    // Only y can have a second possible parent. The swapped choice can
    // contain a directed cycle, in which case build rejects it.
    if (y!=1) {
        int other=parent[y]; parent[y]=x;
        trees.emplace_back(parent,other,y);
        if (!trees.back().build()) trees.pop_back();
    }
    const Tree& base=trees[0];
    auto graphDistance = [&](int a,int b) {
        return min(base.distance(a,b),
            min(base.distance(a,x)+1+base.distance(y,b),
                base.distance(a,y)+1+base.distance(x,b)));
    };
    ll full=INF;
    for (int v=2; v<=n; ++v) {
        int u=v-1;
        ll nextFull=full+graphDistance(u,v), answer=INF;
        for (Tree& t: trees) {
            ll uv=t.distance(u,v), uy=t.distance(u,t.y);
            ll yv=t.distance(t.y,v), ux=t.distance(u,t.x);
            ll yx=t.distance(t.y,t.x);
            // Traverse the final cycle edge x->y after both endpoints
            // have been reached in the tree. The whole cycle is now open.
            ll activate=min(t.visited+ux, t.plain+uy+yx)+1;
            nextFull=min(nextFull,activate+graphDistance(t.y,v));
            t.visited=min(t.visited+uv,t.plain+uy+yv);
            t.plain+=uv;
            answer=min(answer,t.plain);
        }
        full=nextFull;
        printf("%lld\n",min(answer,full));
    }
    return 0;
}
