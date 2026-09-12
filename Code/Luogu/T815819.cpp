#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    auto costEdge = [&](int x, int y, int c) {
        return llabs(p[x] - p[c]) + llabs(p[y] - p[c]);
    };

    ll ans = LLONG_MAX;
    for (int s = 1; s <= n; ++s) {
        if (s == r) continue;
        int t = a[r][s];
        vector<int> rem(n + 1, 0);
        for (int v = 1; v <= n; ++v)
            rem[v] = (v != r && v != s && v != t);

        vector<vector<pair<int, int>>> adj(n + 1);
        for (int x = 1; x <= n; ++x) {
            if (!rem[x]) continue;
            int y1 = a[x][r], y2 = a[x][s];
            if (rem[y1]) adj[x].push_back({y1, r});
            if (rem[y2]) adj[x].push_back({y2, s});
        }

        vector<int> vis(n + 1, 0), compId(n + 1, -1);
        vector<vector<int>> comps;
        for (int x = 1; x <= n; ++x) {
            if (!rem[x] || vis[x]) continue;
            vector<int> comp;
            stack<int> st;
            st.push(x); vis[x] = 1;
            while (!st.empty()) {
                int u = st.top(); st.pop();
                comp.push_back(u);
                for (auto [v, c] : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        st.push(v);
                    }
                }
            }
            sort(comp.begin(), comp.end());
            comps.push_back(comp);
        }

        ll cur = llabs(p[r] - p[t]) + llabs(p[s] - p[t]);
        bool ok = true;
        for (auto &comp : comps) {
            if (comp.size() % 2 == 1) {
                ok = false;
                break;
            }

            // Check both possible alternating perfect matchings.
            bool canR = true, canS = true;
            ll sumR = 0, sumS = 0;
            vector<int> deg(n + 1, 0);
            vector<int> sel(n + 1, -1);
            for (int u : comp) {
                for (auto [v, c] : adj[u]) {
                    if (binary_search(comp.begin(), comp.end(), v)) {
                        deg[u]++;
                    }
                }
            }
            for (int u : comp) {
                if (deg[u] > 2) {
                    ok = false;
                    break;
                }
                if (deg[u] == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;

            vector<int> used(n + 1, 0);
            for (int u : comp) {
                int cntR = 0, cntS = 0;
                for (auto [v, c] : adj[u]) {
                    if (!binary_search(comp.begin(), comp.end(), v)) continue;
                    if (c == r) ++cntR;
                    else ++cntS;
                }
                if (cntR > 0 && cntS > 0) {
                    // in a valid degree-2 component the edges alternate colors, so each vertex can be matched by one of them.
                    // We simply try both selected-color families and verify them.
                }
            }

            // One pass for matching by color r and by color s.
            vector<int> pick(n + 1, 0);
            for (int u : comp) {
                for (auto [v, c] : adj[u]) {
                    if (binary_search(comp.begin(), comp.end(), v) && c == r) {
                        sumR += costEdge(u, v, r);
                        pick[u] ^= 1;
                        pick[v] ^= 1;
                    }
                }
            }
            for (int u : comp) {
                if (pick[u] != 1) {
                    canR = false;
                    break;
                }
            }
            if (canR) {
                cur += sumR;
                continue;
            }

            fill(pick.begin(), pick.end(), 0);
            sumS = 0;
            for (int u : comp) {
                for (auto [v, c] : adj[u]) {
                    if (binary_search(comp.begin(), comp.end(), v) && c == s) {
                        sumS += costEdge(u, v, s);
                        pick[u] ^= 1;
                        pick[v] ^= 1;
                    }
                }
            }
            for (int u : comp) {
                if (pick[u] != 1) {
                    canS = false;
                    break;
                }
            }
            if (!canS) {
                ok = false;
                break;
            }
            cur += sumS;
        }
        if (!ok) continue;
        ans = min(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}
