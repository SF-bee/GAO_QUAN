#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
const long long INF = 1e18;

int n[5];
long long a[MAX], b[MAX], c[MAX], d[MAX];
int a_id[MAX], b_id[MAX], c_id[MAX], d_id[MAX];
unordered_set<int> ban_ab[MAX], ban_bc[MAX], ban_cd[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n[1] >> n[2] >> n[3] >> n[4];
    vector<pair<long long, int>> temp;
    for (int i = 1; i <= n[1]; i++) {
        cin >> a[i];
        temp.push_back({a[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n[1]; i++) {
        a[i+1] = temp[i].first;
        a_id[i+1] = temp[i].second;
    }
    temp.clear();
    for (int i = 1; i <= n[2]; i++) {
        cin >> b[i];
        temp.push_back({b[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n[2]; i++) {
        b[i+1] = temp[i].first;
        b_id[i+1] = temp[i].second;
    }
    temp.clear();
    for (int i = 1; i <= n[3]; i++) {
        cin >> c[i];
        temp.push_back({c[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n[3]; i++) {
        c[i+1] = temp[i].first;
        c_id[i+1] = temp[i].second;
    }
    temp.clear();
    for (int i = 1; i <= n[4]; i++) {
        cin >> d[i];
        temp.push_back({d[i], i});
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n[4]; i++) {
        d[i+1] = temp[i].first;
        d_id[i+1] = temp[i].second;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ban_ab[y].insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ban_bc[y].insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ban_cd[y].insert(x);
    }
    vector<long long> ab(n[2] + 1, INF);
    for (int j = 1; j <= n[2]; j++) {
        int ptr = 1;
        while (ptr <= n[1] && ban_ab[b_id[j]].count(a_id[ptr]))
            ptr++;
        if (ptr <= n[1]) 
            ab[j] = a[ptr] + b[j];
    }
    vector<long long> abc(n[3] + 1, INF);
    vector<pair<long long, int>> sorted_b;
    for (int j = 1; j <= n[2]; j++)
        if (ab[j] < INF)
            sorted_b.push_back({ab[j], b_id[j]});
    sort(sorted_b.begin(), sorted_b.end());
    
    for (int k = 1; k <= n[3]; k++) {
        int ptr = 0;
        while (ptr < sorted_b.size() && ban_bc[c_id[k]].count(sorted_b[ptr].second))
            ptr++;
        if (ptr < sorted_b.size())
            abc[k] = sorted_b[ptr].first + c[k];
    }
    long long ans = INF;
    vector<pair<long long, int>> sorted_c;
    for (int k = 1; k <= n[3]; k++) {
        if (abc[k] < INF)
            sorted_c.push_back({abc[k], c_id[k]});
    }
    sort(sorted_c.begin(), sorted_c.end());
    for (int l = 1; l <= n[4]; l++) {
        int ptr = 0;
        while (ptr < sorted_c.size() && ban_cd[d_id[l]].count(sorted_c[ptr].second))
            ptr++;
        if (ptr < sorted_c.size())
            ans = min(ans, sorted_c[ptr].first + d[l]);
    }
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}