#include <iostream>
#include <string>

typedef long long ll;
const int alpha = 32;
const int maxn = 10000 + 5, maxk = 100 + 5;
const int maxv = 100000 + 5, maxs = 100000 + 5;
const ll mod = 1000000000 + 7; 
using namespace std;

int n, k, v;
ll a[maxv];
string s;
int tr[maxs][alpha], dep[maxs], cnt[maxs];
int nxt[maxs], cnt1;
int id[maxs], cnt2;
ll c[maxn][maxk];
ll dp[maxn * 2][maxk], temp[maxk];
int siz[maxs];

void dfs(int ver) {
int numb = 0, son = 0;
for (int i = 0; i < alpha; i++) {
if(tr[ver][i] != 0) {
dfs(tr[ver][i]);
++numb;
son = tr[ver][i];
}
}
if (ver != 1 && numb == 1 && cnt[ver] == 0) {
nxt[ver] = nxt[son];
} else {
nxt[ver] = ver;
id[ver] = ++cnt2;
}
}
void solve(int ver) {
ll f = 1, g = 1;
siz[ver] = cnt[ver];
for (int i = 0; i <= siz[ver] && i <= k; i++) {
dp[id[ver]][i] = f * c[siz[ver]][i] % mod;
f = f * g % mod;
g = g * a[dep[ver]] % mod;
}
for (int i = 0; i < alpha; i++)
if(tr[ver][i] != 0)
solve(nxt[tr[ver][i]]);
for (int i = 0; i < alpha; i++)
if (tr[ver][i] != 0) {
int x = nxt[tr[ver][i]];
for (int j = 0; j <= k && j <= siz[ver] + siz[x]; j++)
temp[j] = 0;
ll value1 = 1;
for (int j1 = 0; j1 <= k && j1 <= siz[ver]; j1++) {
ll value2 = dp[id[ver]][j1];
for (int j2 = 0; j2 <= siz[x] && j1 + j2 <= k; j2++) {
temp[j1 + j2] = (temp[j1 + j2] + 
value2 * dp[id[x]][j2]) % mod;
value2 = value2 * value1 % mod;
}
value1 = value1 * a[dep[ver]] % mod;
}
siz[ver] += siz[x];
for (int j = 0; j <= siz[ver] && j <= k; j++)
dp[id[ver]][j] = temp[j];
}
}
int main() {
cin >> n >> k >> v;
for (int i = 0; i <= v; i++)
cin >> a[i];
cnt1 = 1;
for (int i = 1; i <= n; i++) {
cin >> s;
int cur = 1, len = s.size();
for (int j = 0; j < len; j++) {
int ch = s[j] & 31;
if (tr[cur][ch] == 0) {
tr[cur][ch] = ++cnt1;
dep[cnt1] = dep[cur] + 1;
}
cur = tr[cur][ch];
}
++cnt[cur];
}
c[0][0] = 1;
for (int i = 1; i <= n; i++) {
c[i][0] = 1;
for (int j = 1; j <= k && j <= i; j++)
c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
}
dfs(1);
solve(1);
cout << dp[id[1]][k] << endl;
return 0;
}
/*
10 3 12
3 1 4 6 5 2 0 3 6 1 4 2 5
ak
firstround
goodluck
havefun
luogu
luogudevteam
luotianyi
rpplusplus
scp
scps
*/