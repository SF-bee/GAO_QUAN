#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *  T840698 "树"
 *  结论：n >= 8 时，有解 <=> a1 + a3 >= 1 （即 a2 == n-1 时无解）。
 *
 *  构造分三块（见 sol.md）：
 *   I  : a1 >= a3+1  : 深度自动机（链式），排列取恒等排列。
 *   II : a3 == 0     : 星 / 链 + 星。
 *   III: a3 >= 1 且 a1 <= a3 : "根 r + 儿子 C + 孙子 D" 结构。
 *   IV : a1 == 0 && a2 == 0  : 全 3 步专用构造（深度 3 的 e 点）。
 */

static int n, a1, a2, a3;
static vector<int> eu, ev;
static vector<int> P;

static inline void addE(int u, int v) {
    if (u > v) swap(u, v);
    eu.push_back(u); ev.push_back(v);
}

/* ---------------- 构造 I：深度自动机 ---------------- */
/* 排列为 1,2,...,n ；步长序列 = a1 个 1，再 a2 个 2，再 a3 个 3。
   维护"根到当前点"的栈；步长 d 时新点接在"当前点向上 d-1 步"的祖先上。 */
static void buildDepth() {
    vector<int> seq;
    seq.reserve(n - 1);
    for (int i = 0; i < a1; i++) seq.push_back(1);
    for (int i = 0; i < a2; i++) seq.push_back(2);
    for (int i = 0; i < a3; i++) seq.push_back(3);
    vector<int> st;
    st.push_back(0);
    P.push_back(0);
    for (int i = 0; i + 1 < n; i++) {
        int d = seq[i];
        int cur = (int)st.size() - 1;
        int need = cur - (d - 1);
        int par = st[need];
        int v = i + 1;
        addE(par, v);
        st.resize(need + 1);
        st.push_back(v);
        P.push_back(v);
    }
}

/* ---------------- 构造 IV：全 3 步 (a1=a2=0, a3=n-1) ---------------- */
static void buildAllThree() {
    if (n % 2 == 0) {
        int k = (n - 2) / 2;      /* k 个 C、k 个 D、1 个 e，加上 r */
        int r = 0, e = 2 * k + 1;
        for (int i = 1; i <= k; i++) addE(r, i);                 /* r - C_i */
        for (int j = 1; j <= k; j++) {                           /* C_p - D_j */
            int p = (j <= 2) ? 1 : j;
            addE(p, k + j);
        }
        addE(k + 1, e);                                          /* D_1 - e */
        vector<int> tau(k + 1);
        if (k == 3) { tau[1] = 3; tau[2] = 2; tau[3] = 1; }
        else for (int i = 1; i <= k; i++) tau[i] = ((i + 1) % k) + 1;
        P.push_back(r); P.push_back(e);
        P.push_back(k + 2); P.push_back(tau[1]);
        P.push_back(k + 1); P.push_back(tau[2]);
        for (int i = 3; i <= k; i++) { P.push_back(k + i); P.push_back(tau[i]); }
    } else {
        int k = (n - 3) / 2;      /* k 个 C、k+1 个 D、1 个 e、r */
        int r = 0, e = 2 * k + 2;
        for (int i = 1; i <= k; i++) addE(r, i);
        for (int j = 1; j <= k + 1; j++) {
            int p;
            if (j <= 2) p = 1; else if (j <= k) p = j; else p = k;
            addE(p, k + j);
        }
        addE(k + 1, e);
        vector<int> tau(k + 1);
        if (k == 3) { tau[1] = 3; tau[2] = 2; tau[3] = 1; }
        else for (int i = 1; i <= k; i++) tau[i] = ((i + 1) % k) + 1;
        P.push_back(r); P.push_back(e);
        P.push_back(k + 2); P.push_back(tau[1]);
        P.push_back(k + 1); P.push_back(tau[2]);
        for (int i = 3; i <= k; i++) { P.push_back(k + i); P.push_back(tau[i]); }
        P.push_back(2 * k + 1);
    }
}

/* ---------------- 构造 III：根 r + 儿子 C + 孙子 D ----------------
 * 结构：r=0；C = 1..k（r 的儿子）；D = k+1..k+L（C 的儿子）。
 * 排列：r, 然后若干"游程"（C 游程内相邻距离 2，D 游程内相邻是兄弟、距离 2），
 * 相邻游程之间的跨步为 1（C 与自己的儿子）或 3（C 与非自己儿子）。
 * r->C 为 1，r->D 为 2。
 */
static void buildFlat() {
    int delta = (a2 >= 1) ? 1 : 0;          /* 1: 第一步 r->D(2)，0: r->C(1) */
    int S = (a2 >= 1) ? a2 - 1 : 0;         /* 游程内部的 2 步数 */
    int X = a1 + a3 - (delta ? 0 : 1);      /* 跨游程步数 */
    int v1 = a1 - (delta ? 0 : 1);          /* 其中要用 1 步的个数 */
    int runs = X + 1;
    int nD, nC;
    if (delta) { nD = (runs + 1) / 2; nC = runs / 2; }
    else       { nC = (runs + 1) / 2; nD = runs / 2; }

    int ec = max(0, 3 - nC); if (ec > S) ec = S;
    int ed = S - ec;
    int k = nC + ec;

    vector<int> rtype(runs + 1), rsz(runs + 1, 1);
    for (int r = 1; r <= runs; r++) {
        if (delta) rtype[r] = (r % 2 == 1) ? 1 : 0;
        else       rtype[r] = (r % 2 == 1) ? 0 : 1;
    }
    for (int r = 1; r <= runs; r++) if (rtype[r] == 0) { rsz[r] += ec; break; }
    for (int r = 1; r <= runs; r++) if (rtype[r] == 1) { rsz[r] += ed; break; }

    P.push_back(0);
    int cp = 1, dp = 1;
    vector<int> dA(runs + 1), dB(runs + 1), cBefore(runs + 1), cAfter(runs + 1, 0);
    int cEmit = 0;
    for (int r = 1; r <= runs; r++) {
        if (rtype[r] == 1) {
            dA[r] = dp; cBefore[r] = cEmit;
            for (int t = 0; t < rsz[r]; t++) { P.push_back(k + dp); dp++; }
            dB[r] = dp - 1;
        } else {
            for (int t = 0; t < rsz[r]; t++) { P.push_back(cp); cp++; cEmit++; }
        }
    }
    for (int r = 1; r <= runs; r++)
        if (rtype[r] == 1 && cBefore[r] + 1 <= k) cAfter[r] = cBefore[r] + 1;

    for (int i = 1; i <= k; i++) addE(0, i);

    vector<int> parentOf(runs + 1, 0);
    int used = 0;
    for (int r = 1; r <= runs && used < v1; r++) {
        if (rtype[r] != 1) continue;
        if (cBefore[r] >= 1) { parentOf[r] = cBefore[r]; used++; }
        else if (cAfter[r] >= 1) { parentOf[r] = cAfter[r]; used++; }
    }
    for (int r = 1; r <= runs; r++) {
        if (rtype[r] != 1 || parentOf[r] != 0) continue;
        int par = -1;
        for (int c = 1; c <= k; c++) {
            if (cBefore[r] >= 1 && c == cBefore[r]) continue;
            if (cAfter[r] >= 1 && c == cAfter[r]) continue;
            par = c; break;
        }
        parentOf[r] = par;
    }
    for (int r = 1; r <= runs; r++) {
        if (rtype[r] != 1) continue;
        for (int t = dA[r]; t <= dB[r]; t++) addE(parentOf[r], k + t);
    }
}

/* ---------------- 构造 II：a3 == 0 ---------------- */
static void buildNoThree() {
    if (a1 == 1) {                       /* 星：中心 + (n-1) 个叶子 */
        for (int i = 1; i < n; i++) addE(0, i);
        for (int i = 0; i < n; i++) P.push_back(i);
    } else {                             /* 链 0..a1-2 ，再挂中心 a1-1 与其叶子 */
        for (int i = 0; i + 1 <= a1 - 2; i++) addE(i, i + 1);
        int center = a1 - 1;
        addE(a1 - 2, center);
        for (int i = a1; i < n; i++) addE(center, i);
        for (int i = 0; i <= a1 - 2; i++) P.push_back(i);
        P.push_back(center);
        for (int i = a1; i < n; i++) P.push_back(i);
    }
}

static void solve() {
    eu.clear(); ev.clear(); P.clear();
    if (a1 + a3 == 0) return;                    /* 无解 */
    if (a3 == 0) { buildNoThree(); return; }
    if (a1 >= a3 + 1) { buildDepth(); return; }
    if (a1 == 0 && a2 == 0) { buildAllThree(); return; }
    buildFlat();
}

static char obuf[1 << 22];
static int opos = 0;
static inline void wint(int x) {
    if (opos > (1 << 22) - 24) { fwrite(obuf, 1, opos, stdout); opos = 0; }
    char tmp[12]; int l = 0;
    if (x == 0) tmp[l++] = '0';
    while (x > 0) { tmp[l++] = char('0' + x % 10); x /= 10; }
    while (l > 0) obuf[opos++] = tmp[--l];
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        scanf("%d %d %d %d", &n, &a1, &a2, &a3);
        solve();
        if (a1 + a3 == 0) {
            if (opos > (1 << 22) - 3) { fwrite(obuf, 1, opos, stdout); opos = 0; }
            obuf[opos++] = '-'; obuf[opos++] = '1'; obuf[opos++] = '\n';
            continue;
        }
        int sz = (int)eu.size();
        for (int i = 0; i < sz; i++) {
            wint(eu[i] + 1); obuf[opos++] = ' ';
            wint(ev[i] + 1); obuf[opos++] = '\n';
        }
        for (int i = 0; i < n; i++) {
            wint(P[i] + 1);
            obuf[opos++] = (i + 1 == n) ? '\n' : ' ';
        }
    }
    if (opos) fwrite(obuf, 1, opos, stdout);
    return 0;
}
