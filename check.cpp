// check.cpp -- brute-force verifier for small n
#include <bits/stdc++.h>
using namespace std;

/*
 We implement:
 - algorithmA: the SCC-based solution (count single-node SCCs with indegree 0 -> answer = 1 - c/n)
 - bruteForce: enumerate all possible interrogation strategies under the "best luck" rules to check
   whether for a fixed killer k, it is possible to find k without interrogating k.
 For small n (<=8..10) bruteForce is feasible.
*/

int n;
vector<vector<int>> edges;

// compute SCCs via simple Kosaraju (easy to code)
vector<int> scc_id_kosaraju(const vector<vector<int>>& g) {
    int N = (int)g.size();
    vector<int> vis(N,0), order;
    function<void(int)> dfs1 = [&](int u){
        vis[u]=1;
        for(int v: g[u]) if(!vis[v]) dfs1(v);
        order.push_back(u);
    };
    for(int i=0;i<N;i++) if(!vis[i]) dfs1(i);
    vector<vector<int>> gr(N);
    for(int u=0;u<N;u++) for(int v: g[u]) gr[v].push_back(u);
    vector<int> comp(N,-1);
    int cid=0;
    function<void(int)> dfs2 = [&](int u){
        comp[u]=cid;
        for(int v: gr[u]) if(comp[v]==-1) dfs2(v);
    };
    for(int i=N-1;i>=0;i--){
        int u=order[i];
        if(comp[u]==-1){ dfs2(u); cid++; }
    }
    return comp;
}

double algorithmA(const vector<vector<int>>& g) {
    int N = (int)g.size();
    auto comp = scc_id_kosaraju(g);
    int C = 0;
    for(int x: comp) C = max(C, x+1);
    vector<int> sz(C,0), indeg(C,0);
    for(int i=0;i<N;i++) sz[comp[i]]++;
    for(int u=0;u<N;u++) for(int v: g[u]) if(comp[u]!=comp[v]) indeg[comp[v]]++;
    int c = 0;
    for(int i=0;i<C;i++) if(indeg[i]==0 && sz[i]==1) c++;
    return 1.0 - double(c) / double(N);
}

// Brute: for each possible killer k, check if there is any sequence of interrogations (adapative, with "best luck")
// that will identify k without ever interrogating k.
// Model the process: we choose a person p to ask (we can choose only persons who are "possible non-killer" under current knowledge).
// Under best luck, if p might not be killer, he will be non-killer and will reveal his known nodes (set of nodes reachable from p).
// After revealing, we can eliminate those revealed nodes? We must simulate deductive process to see if we can uniquely determine k.
bool can_identify_without_asking_k(const vector<vector<int>>& g, int k) {
    int N = (int)g.size();
    // Precompute reachability sets (who each person knows) via BFS/DFS
    vector<bitset<16>> reach(N);
    for(int u=0; u<N; ++u){
        vector<int> q; vector<int> vis(N,0);
        q.push_back(u); vis[u]=1;
        for(size_t i=0;i<q.size();i++){
            int x=q[i];
            for(int v: g[x]) if(!vis[v]) { vis[v]=1; q.push_back(v); }
        }
        for(int i=0;i<N;i++) if(vis[i]) reach[u].set(i);
    }
    // Initially possible killers = all nodes 0..N-1 uniformly.
    bitset<16> possible; possible.reset();
    for(int i=0;i<N;i++) possible.set(i);
    // We'll do DFS over interrogation choices. Limit depth to N.
    // state: current possible set (bitset), and set of already-asked persons (so we don't repeat).
    set<pair<unsigned long long, unsigned long long>> seen; // memo (possible, askedMask) to prune
    function<bool(bitset<16>, int)> dfs = [&](bitset<16> poss, int askedMask) -> bool {
        // If poss has size 1 and equals {k}, we identified k without asking k
        if(poss.count() == 1) {
            if(poss.test(k)) return true;
            else return false;
        }
        // If all remaining possible nodes include k and all of them are unreachable by any safe interrogatee, we may be stuck.
        unsigned long long key1 = 0;
        for(int i=0;i<N;i++) if(poss.test(i)) key1 |= (1ULL<<i);
        unsigned long long key2 = askedMask;
        if(seen.count({key1,key2})) return false;
        seen.insert({key1,key2});
        // We may choose any person p to ask, BUT under "best luck", we cannot ask someone who is surely the killer.
        // The rule: "只要 x 被调查过存在不是凶手的可能性，就一定不是凶手" — we interpret as:
        // If a person p is in the current possible set 'poss', then p may be the killer; but we can still ask p only if there exists some possibility that p is NOT the killer.
        // That is, if p is not forced to be killer (i.e., poss contains others than p), then under best luck asking p will be a non-killer.
        // So allowed to ask p iff poss has at least one node != p (i.e., poss.count() > 1) — but that's always true here.
        // But we must avoid asking the actual killer k (we're testing if there exists a strategy that never asks k).
        for(int p=0;p<N;p++){
            if(askedMask & (1<<p)) continue; // skip already asked
            // Under our strategy we may choose p to ask only if there exists possibility that p is not killer.
            // That is, if poss.count() > 1 or poss does not equal {p}.
            if(poss.count() == 1 && poss.test(p)) continue; // can't ask only possible killer
            if(p == k) continue; // we must never ask k for this test
            // Under best luck, if p might be non-killer, we assume he is non-killer and will reveal reach[p].
            // When p reveals reach[p], we learn the identities of all nodes in reach[p], i.e., we know which ones are not killer? How to update poss:
            // If p reveals some nodes and none of them are the killer (since p is non-killer), we can remove those nodes from poss (they're revealed as not killer).
            // But more precisely: p will tell us identities of those people (who they are: good/bad?), The problem statement: "x 会知道 y 的身份" — they know identity (good/bad).
            // So asking p gives us, for all v in reach[p], whether v is killer or not. If any of them is killer, p would reveal killer (but then p might be killer? but we assume p non-killer).
            // Therefore after asking p (non-killer), we can eliminate all v in reach[p] from possible killers (they are revealed not killer), EXCEPT if one of them is actually the killer k, in which case we'd have found k (but that contradicts not asking k).
            bitset<16> newposs = poss;
            for(int v=0; v<N; ++v) if(reach[p].test(v)) newposs.reset(v);
            // If asking p would immediately reveal k (i.e., reach[p] contains k), then we'd find k (success).
            if(reach[p].test(k)) return true;
            // otherwise continue search
            if(dfs(newposs, askedMask | (1<<p))) return true;
        }
        return false;
    };

    return dfs(possible, 0);
}

// brute force compute probability = fraction of k in 0..N-1 for which can_identify_without_asking_k==true
double brute(const vector<vector<int>>& g) {
    int N = (int)g.size();
    int can=0;
    for(int k=0;k<N;k++){
        if(can_identify_without_asking_k(g,k)) can++;
    }
    return double(can)/double(N);
}

int main(){
    // Small search: try all graphs up to N=6 (2^(N*(N-1)) graphs) is big; we will random sample for speed.
    int N = 6;
    n = N;
    mt19937_64 rng(123456);
    for(int iter=0; iter<200000; ++iter){
        vector<vector<int>> g(N);
        for(int u=0;u<N;u++){
            for(int v=0;v<N;v++){
                if(u==v) continue;
                if((rng() & 1) == 0) g[u].push_back(v);
            }
        }
        double a = algorithmA(g);
        double b = brute(g);
        if (fabs(a-b) > 1e-9) {
            cerr << "Found mismatch! N=" << N << "\n";
            cerr << "Edges:\n";
            for(int u=0;u<N;u++) for(int v: g[u]) cerr << u+1 << ' ' << v+1 << "\n";
            cerr << "AlgA="<< a <<" Brute=" << b << "\n";
            return 0;
        }
    }
    cerr << "No mismatch found in random search.\n";
    return 0;
}