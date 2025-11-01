#include "testlib.h"
bool vis[1 << 20 | 5]; int c[1 << 10 | 5];
inline int lowbit(int x) { return x & -x; }
inline void init() { for (int i = 1;i < (1 << 10);++ i) c[i] = c[i ^ lowbit(i)] + 1; }
inline int popc(const int x) { return c[x & 1023] + c[x >> 10]; }
int main(int argc, char ** argv){
    registerTestlibCmd(argc, argv);
    init(); const int n = inf.readInt(); const int m = inf.readInt();
    const int tmp = (n > m && (m & 1)) || (!n) || (n == 1 && m == 1);
    const int N = 1 << n; int pre = ouf.readInt(0, N - 1); vis[pre] = 1;
        for (int i = 1;i < N;++ i) {
            int x = ouf.readInt(0, N - 1);
            if(vis[x] || popc(x ^ pre) != m) quitf(_wa, "sorry the answer is wrong.\n");
            vis[x] = 1; pre = x;
        }
	quitf(_ok, "ok, correct output.\n");
}
