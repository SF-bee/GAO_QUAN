#include "testlib.h"
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    const int T = inf.readInt(1, 100, "T");
    for (int tc = 1; tc <= T; ++tc) {
        const int a = inf.readInt(1, 100, "a");
        const int b = inf.readInt(1, 100, "b");
        const int c = inf.readInt(1, 100, "c");
        const int optimal = std::max(a * b, std::max(a * c, b * c));
        const int m = ouf.readInt();
        if (m != optimal) {
            quitf(_wa, "Case %d: expected %d cubes, found %d", tc, optimal, m);
        }

        bool xy[101][101] = {};
        bool xz[101][101] = {};
        bool yz[101][101] = {};
        std::vector<bool> used(a * b * c, false);
        for (int i = 1; i <= m; ++i) {
            const int x = ouf.readInt(1, a, "x");
            const int y = ouf.readInt(1, b, "y");
            const int z = ouf.readInt(1, c, "z");
            const int id = ((x - 1) * b + y - 1) * c + z - 1;
            if (used[id]) {
                quitf(_wa, "Case %d: duplicate cube (%d, %d, %d)", tc, x, y, z);
            }
            used[id] = true;
            xy[x][y] = xz[x][z] = yz[y][z] = true;
        }

        for (int x = 1; x <= a; ++x) {
            for (int y = 1; y <= b; ++y) {
                if (!xy[x][y]) {
                    quitf(_wa, "Case %d: missing projection (x, y) = (%d, %d)", tc, x, y);
                }
            }
        }
        for (int x = 1; x <= a; ++x) {
            for (int z = 1; z <= c; ++z) {
                if (!xz[x][z]) {
                    quitf(_wa, "Case %d: missing projection (x, z) = (%d, %d)", tc, x, z);
                }
            }
        }
        for (int y = 1; y <= b; ++y) {
            for (int z = 1; z <= c; ++z) {
                if (!yz[y][z]) {
                    quitf(_wa, "Case %d: missing projection (y, z) = (%d, %d)", tc, y, z);
                }
            }
        }
    }

    if (!ouf.seekEof()) {
        quitf(_wa, "Extra output after all test cases");
    }
    quitf(_ok, "All %d test cases passed", T);
}
