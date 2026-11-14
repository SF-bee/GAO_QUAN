#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n, K;
int S[MAX];
std::bitset<MAX> a[31];
std::unordered_map<int, int> f;
std::unordered_map<int, std::bitset<MAX>> B;

struct cmp {
    bool operator()(std::pair<int, int> x, std::pair<int, int> y) const {
        return f[x.first] < f[y.first];
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> K;
    for (int i = 1; i <= n; i++) {
        std::cin >> S[i];
        for (int k = 0; k <= 30; k++)
            if (S[i] & (1 << k)) a[k][i] = 1;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> q;
    std::unordered_set<int> ans;
    f[(1 << 30) - 1] = n;
    std::bitset<MAX> mask;
    mask.set(), mask >>= (MAX - n - 1), mask[0] = 0, B[(1 << 30) - 1] = mask;
    for (q.push({(1 << 30) - 1, -1}); ans.size() < K;) {
        auto [u, pre] = q.top();
        q.pop();
        ans.insert(u);
        if (ans.size() == K) break;
        if (pre != -1) B[u] = B[u | (1 << pre)] & (~a[pre]);
        // 删除路径是唯一的
        for (int k = pre + 1; k <= 30; k++) {
            if (u & (1 << k)) {
                int t = u ^ (1 << k);
                if (t == 0) continue;
                std::bitset<MAX> bt = B[u] & (~a[k]);
                f[t] = bt.count();
                q.push({t, k});
            }
        }
    }
    for (auto i : ans)
        std::cout << i << ' ';
    return 0;
}
/*
给定一个大小为 n 的集合 S
构造一个大小为 K 的集合 T
使得 \sum_{x\in{T}} \sum_{y\in{S}} [x \& y = y] 最大
转化一下视角，\sum_{y\in{S}} [x \& y = y] 是给定的，
我们其实就是在[0,2^30]里找出K个整数然后把 \sum_{y\in{S}} [x \& y = y] 求和
记 f(x) = \sum_{y\in{S}} [x \& y = y]
那么直观地，我们直接搞出2^30个元素然后取前 K 个 max 不就好了（啥子
我们需要一些更强的性质？考虑怎么样的元素 x 是在 mid 之前的？
回到定义，说明它覆盖的元素比 mid 多
考虑集合 S 中的元素，覆盖的元素必然是选择若干个，然后或起来，
然后这个元素就是可以覆盖这些元素的
哎？或起来？得到 U
也就是说，不考的那就不学！所以完全不需要考虑那些不考的知识点！
接着就是，我缺的越少，那么我的精彩度就一定不会越低
然后我刷题肯定去刷越牛的题越好，换句话说，我们只需要从 U 开始字集枚举，然后扣掉一些知识点，
然后枚举这些被扣掉的就可以了
这些被扣掉的有多少？
*/
