#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n;
int a[MAX];

struct SegmentTree {
    struct node {
        int mHp, cmHp;
        int Dead = 0;
        int mSp = 0, cmSp = 1;
        int tagHp = 0, tagSp = 0;
    } tre[MAX << 2];
#define ls(p) (p >> 1)
#define rs(p) (p >> 1 | 1)
    void Build(int p, int l, int r) {
        if (l == r) {
            tre[p].mHp = a[l];
            tre[p].cmHp = 1;
            tre[p].Dead = 0;
        }
        int mid = (l + r) >> 1;
        Build(ls(p), l, mid);
        Build(rs(p), mid + 1, r);
    }
    void PushUp(int p) {
        tre[p].mHp = std::min(tre[ls(p)].mHp, tre[rs(p)].mHp);
        int cmHp = 0;
        if (tre[ls(p)].mHp == tre[p].mHp) cmHp += tre[ls(p)].cmHp;
        if (tre[rs(p)].mHp == tre[p].mHp) cmHp += tre[rs(p)].cmHp;
        tre[p].cmHp = cmHp;

        tre[p].mSp = std::min(tre[ls(p)].mSp, tre[rs(p)].mSp);
        int cmSp = 0;
        if (tre[ls(p)].mSp == tre[p].mSp) cmSp += tre[ls(p)].cmSp;
        if (tre[rs(p)].mSp == tre[p].mSp) cmSp += tre[rs(p)].cmSp;
        tre[p].cmSp = cmSp;

        tre[p].Dead = tre[ls(p)].Dead + tre[rs(p)].Dead;
    }

    void 
#undef ls
#undef rs
};

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    return 0;
}
/*
数据结构好题（好存疑？
从部分分开始想：
1、只有攻击，回血，查询濒死，没有死亡
维护区间的最小值和最小值的人数，那么：
攻击，回血：区间和差
查询濒死，返回最小值人数
2、只有攻击，回血，加盾，查询濒死，没有死亡
增加盾量的维护，维护区间内盾量的最小值，达到最小值的人数
攻击操作增加维护
i.都有护盾,全部扣盾
ii. 都没护盾，全部扣血
iii. 鱼龙混杂，递归
3、只有攻击，查询濒死，查询死亡
如果最小值低于 0，说明有人死了，递归下去，找子区间里的死人
找到一个区间内全死死人，把这些人移除维护（就是返回一个巨大的生命值，这样最小值就一定不会被影响
然后再维护一个区间死人数
但是这里护盾怎么办呢？我们需要给死人套盾吗？这样会不会影响正确性？
*/
