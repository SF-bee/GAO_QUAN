#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
using i64 = long long;

/*
 * f(l,r) = x[r]-x[l] - sum_{l<i<r} h_i,
 * h_i = max(0, max_{l<=j<i} x[j]-x[i], x[i]-min_{i<j<=r} x[j]).
 * A segment-tree node stores the same h_i restricted to that node.
 * External prefix maximum M / suffix minimum m change its contribution to
 * max(h_i, M-x[i], x[i]-m).  Split at 2*x[i] <= M+m; the two extra sums
 * become static 2D dominance queries, answered offline with Fenwick trees.
 * Time O((n+q) log^2 n), space O(n + q log n).
 */
struct FastInput {
    char buf[1 << 16]; int pos = 0, len = 0;
    int get() {
        if (pos == len) { len = (int)fread(buf, 1, sizeof(buf), stdin); pos = 0; }
        return pos < len ? buf[pos++] : EOF;
    }
    int read() {
        int c = get(), sign = 1, v = 0;
        while (c != EOF && c <= ' ') c = get();
        if (c == '-') { sign = -1; c = get(); }
        while (c >= '0' && c <= '9') { v = v * 10 + c - '0'; c = get(); }
        return v * sign;
    }
};
struct Record { int query, next, leftMax, rightMin; };
struct Request { int query, leftMax, rightMin, cut; };
struct Point { int value, height, rank; };
struct Fenwick {
    vector<int> count;
    vector<i64> sum;
    explicit Fenwick(int n) : count(n + 1), sum(n + 1) {}
    void reset() { fill(count.begin(), count.end(), 0); fill(sum.begin(), sum.end(), 0); }
    void add(int p, i64 v) {
        for (; p < (int)count.size(); p += p & -p) { ++count[p]; sum[p] += v; }
    }
    pair<int, i64> prefix(int p) const {
        int c = 0; i64 s = 0;
        for (; p > 0; p -= p & -p) { c += count[p]; s += sum[p]; }
        return {c, s};
    }
};
static const int LOW = -2000000001, HIGH = 2000000001;
int n, q;
vector<int> x, mn, mx, first;
vector<Record> records;
vector<i64> answer;

void build(int p, int l, int r) {
    if (l == r) { mn[p] = mx[p] = x[l]; return; }
    int mid = (l + r) / 2;
    build(p * 2, l, mid); build(p * 2 + 1, mid + 1, r);
    mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
    mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}
void collect(int p, int l, int r, int ql, int qr, vector<int>& nodes) {
    if (ql <= l && r <= qr) { nodes.push_back(p); return; }
    int mid = (l + r) / 2;
    if (ql <= mid) collect(p * 2, l, mid, ql, qr, nodes);
    if (qr > mid) collect(p * 2 + 1, mid + 1, r, ql, qr, nodes);
}

void process(int p, int l, int r) {
    if (first[p] != -1) {
        if (l == r) {
            for (int t = first[p]; t != -1; t = records[t].next) {
                const auto& a = records[t];
                answer[a.query] -= max({0LL, (i64)a.leftMax - x[l], (i64)x[l] - a.rightMin});
            }
        } else {
            int len = r - l + 1;
            vector<Point> pts(len);
            int pref = LOW;
            for (int i = l; i <= r; ++i) {
                pref = max(pref, x[i]);
                pts[i - l] = {x[i], pref - x[i], 0};
            }
            int suff = HIGH; i64 base = 0;
            for (int i = r; i >= l; --i) {
                suff = min(suff, x[i]);
                pts[i - l].height = max(pts[i - l].height, x[i] - suff);
                base += pts[i - l].height;
            }
            sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) { return a.value < b.value; });
            vector<int> values(len);
            for (int i = 0; i < len; ++i) { values[i] = pts[i].value; pts[i].rank = i + 1; }
            vector<Request> req;
            for (int t = first[p]; t != -1; t = records[t].next) {
                const auto& a = records[t];
                i64 twice = (i64)a.leftMax + a.rightMin;
                // floor(twice/2), including negative odd numbers.
                i64 threshold = twice >= 0 ? twice / 2 : -((-twice + 1) / 2);
                int cut = int(upper_bound(values.begin(), values.end(), threshold) - values.begin());
                req.push_back({a.query, a.leftMax, a.rightMin, cut});
                answer[a.query] -= base;
            }
            Fenwick bit(len);
            sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
                return (i64)a.height + a.value < (i64)b.height + b.value;
            });
            vector<i64> keys(len);
            vector<int> bucket(len + 1, -1), next(req.size());
            for (int i = 0; i < len; ++i) keys[i] = (i64)pts[i].height + pts[i].value;
            for (int j = 0; j < (int)req.size(); ++j) {
                int k = int(lower_bound(keys.begin(), keys.end(), (i64)req[j].leftMax) - keys.begin());
                next[j] = bucket[k]; bucket[k] = j;
            }
            for (int at = 0; at <= len; ++at) {
                if (at) bit.add(pts[at - 1].rank, keys[at - 1]);
                for (int j = bucket[at]; j != -1; j = next[j]) {
                    const auto& a = req[j];
                    auto s = bit.prefix(a.cut);
                    answer[a.query] -= (i64)a.leftMax * s.first - s.second;
                }
            }
            bit.reset();
            sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
                return (i64)a.height - a.value < (i64)b.height - b.value;
            });
            fill(bucket.begin(), bucket.end(), -1);
            for (int i = 0; i < len; ++i) keys[i] = (i64)pts[i].height - pts[i].value;
            for (int j = 0; j < (int)req.size(); ++j) {
                int k = int(lower_bound(keys.begin(), keys.end(), -(i64)req[j].rightMin) - keys.begin());
                next[j] = bucket[k]; bucket[k] = j;
            }
            i64 total = 0;
            for (int at = 0; at <= len; ++at) {
                if (at) { bit.add(pts[at - 1].rank, keys[at - 1]); total += keys[at - 1]; }
                for (int j = bucket[at]; j != -1; j = next[j]) {
                    const auto& a = req[j];
                    auto s = bit.prefix(a.cut);
                    answer[a.query] -= -(i64)a.rightMin * (at - s.first) - (total - s.second);
                }
            }
        }
    }
    if (l < r) {
        int mid = (l + r) / 2;
        process(p * 2, l, mid); process(p * 2 + 1, mid + 1, r);
    }
}
int main() {
    FastInput in;
    n = in.read(); q = in.read();
    if (n <= 0) return 0;
    x.resize(n + 1); mn.resize(4 * n + 4); mx.resize(4 * n + 4);
    first.assign(4 * n + 4, -1); answer.resize(q);
    for (int i = 1; i <= n; ++i) x[i] = in.read();
    build(1, 1, n);
    vector<int> nodes, suffix, queryLeft(q), queryRight(q);
    size_t totalRecords = 0;
    for (int id = 0; id < q; ++id) {
        queryLeft[id] = in.read(); queryRight[id] = in.read();
        if (queryLeft[id] == queryRight[id]) continue;
        nodes.clear(); collect(1, 1, n, queryLeft[id], queryRight[id], nodes);
        totalRecords += nodes.size();
    }
    // Reserve exactly once: avoid a large reallocation peak on adversarial intervals.
    records.reserve(totalRecords);
    for (int id = 0; id < q; ++id) {
        int l = queryLeft[id], r = queryRight[id];
        if (l == r) { answer[id] = 0; continue; }
        nodes.clear(); collect(1, 1, n, l, r, nodes);
        int count = (int)nodes.size(), lo = HIGH, hi = LOW;
        suffix.assign(count + 1, HIGH);
        for (int j = count - 1; j >= 0; --j) {
            suffix[j] = min(suffix[j + 1], mn[nodes[j]]);
            lo = min(lo, mn[nodes[j]]); hi = max(hi, mx[nodes[j]]);
        }
        // Formula sums only interior vertices; add back the two endpoints.
        answer[id] = (i64)x[r] - x[l] + max(0LL, (i64)x[l] - lo) + max(0LL, (i64)hi - x[r]);
        int pref = LOW;
        for (int j = 0; j < count; ++j) {
            int p = nodes[j];
            records.push_back({id, first[p], pref, suffix[j + 1]});
            first[p] = (int)records.size() - 1;
            pref = max(pref, mx[p]);
        }
    }
    process(1, 1, n);
    for (i64 v : answer) printf("%lld\n", v);
    return 0;
}
