#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int x1, x2, y3, y2, n;

struct Point {
    int x, y;
    long long u, v;
} a[100011];

bool cmp(Point a, Point b) {
    return a.u < b.u;
}

int main() {
    cin >> x1 >> y3 >> x2 >> y2 >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].u = (a[i].x - x1) * (a[i].x - x1) + (a[i].y - y3) * (a[i].y - y3);
        a[i].v = (a[i].x - x2) * (a[i].x - x2) + (a[i].y - y2) * (a[i].y - y2);
    }

    sort(a, a + n, cmp);

    long long mx = 0x7fffffff;

    for (int i = n - 2; i >= 0; i--) {
        a[i].v = max(a[i + 1].v, a[i].v);
        mx = min(a[i].u + a[i + 1].v, mx);
    }

    mx = min(a[0].v, mx);

    cout << mx;

    return 0;
}