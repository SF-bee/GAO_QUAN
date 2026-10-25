#include <cstdio>
#include <cstring>

/*
 *  T840697 "01串"
 *
 *  模型：把 s 分成若干极长的 1 段（block），相邻 1 段之间是长度为 g 的 0 段（gap）。
 *  - 长度 >= 2 的 1 段每轮向左右各扩展一格（两侧 delay 都为 0）。
 *  - 长度 == 1 的 1 段第一轮只能扩展一侧，此后可两端扩张，等价于一侧 delay 0、另一侧 delay 1。
 *  于是位置被占据的时刻 = min over blocks (dist + 该侧 delay)，
 *  一个 gap 的填满时间 = ceil((g + δ_left + δ_right)/2)，
 *  前缀（长度 P）时间 = P + δ_left，后缀同理。
 *
 *  判定"能否在 T 轮内全 1"：每个 gap 要求 g <= 2T 且 δ_left+δ_right <= cap=min(2,2T-g)；
 *  前缀 cap=(P>0 && P==T)?0:2，后缀同理。孤立的 1 段恰消耗 1 单位 cap，
 *  从左往右贪心：优先把 delay 塞进左边的 gap（它之后再没有别的 1 段可用）。
 *  答案 = 最小的可行 T（对 T 单调，二分即可）。
 */

static const int MAXN = 1000005;
static char s[MAXN];
static int gapLen[MAXN];      /* gapLen[i]: 第 i 个 gap 的长度（i=0..kk） */
static int blockLen[MAXN];    /* blockLen[i]: 第 i 个 1 段的长度 */
static int cap[MAXN];

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int n;
        scanf("%d %s", &n, s);
        int i = 0;
        int P = 0;
        while (i < n && s[i] == '0') i++;
        P = i;
        if (i >= n) { puts("-1"); continue; }   /* 没有 1（题面保证不会出现） */
        int kk = 0;                              /* 1 段个数 */
        int S = 0;
        gapLen[0] = P;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == '1') j++;
            blockLen[kk++] = j - i;
            i = j;
            int e = i;
            while (e < n && s[e] == '0') e++;
            gapLen[kk] = e - i;
            i = e;
        }
        S = gapLen[kk];
        /* 可行性判定 */
        auto feasible = [&](int t) -> bool {
            if (P > t || S > t) return false;
            cap[0] = (P > 0 && P == t) ? 0 : 2;
            cap[kk] = (S > 0 && S == t) ? 0 : 2;
            for (int g = 1; g < kk; g++) {
                if (gapLen[g] > 2 * t) return false;
                int c = 2 * t - gapLen[g];
                cap[g] = c > 2 ? 2 : c;
            }
            for (int b = 0; b < kk; b++) {
                if (blockLen[b] != 1) continue;
                if (cap[b] > 0) cap[b]--;
                else if (cap[b + 1] > 0) cap[b + 1]--;
                else return false;
            }
            return true;
        };
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", lo);
    }
    return 0;
}
