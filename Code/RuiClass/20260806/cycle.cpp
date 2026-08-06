#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

std::string S, A[MAX];
int n, m, a[MAX], T;
int pi[MAX];
std::unordered_set<int> bder[MAX];
void GetA() {
    n = S.size();
    for (int i = 0; i < n; ++i) {
        if (S[i] >= 'A' && S[i] <= 'Z')
            S[i] += 32;
    }
    S = '&' + S;
}
void Border() {
    for (int i = 1; i <= n; i++) {
        int j = pi[i - 1];
        while (j > 0 && S[i] != S[j])
            j = pi[j - 1];
        if (S[i] == S[j])
            j++;
        pi[i] = j;
    }
    for (int i = 1; i <= n; i++) {
        int j = pi[i];
        do {
            bder[i].insert(j);
            j = pi[j];
        } while (j);
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> S;
    GetA();
    Border();

    return 0;
}
/*
考虑预处理每个位置pos的所有合法长度
注意到长度大于等于串长的len总是合法的
因此只考虑小于串长的len
然后串是一个一个字符増长的，所以这个预处理必然与新增的字符相关
1、长度 1 的串合法长度为 0
2、长度为 2 的串合法长度为 1 当且仅当两个字符相同
很像前缀函数
非常像border啊
一个len合法当且仅当L - len = k
其中 k 为L中所有合法border的长度
考虑如何预处理每个串的Border长度


现在考虑如何处理询问
询问等价于查询a[L,R]中最小在bder[pos]中有出现的元素
如果两个都有序的话非常好做
双指针匹配即可，但是其实也不是很好，最坏还是n^2
肯定要离线。
对于询问按照pos分组，然后组内按照l,r升序回答


*/