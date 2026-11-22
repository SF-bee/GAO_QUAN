#include <bits/stdc++.h>

int T;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> T;
    while (T--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a * b >= b * c && a * b >= a * c) {
            int cnt = 0;
            std::cout << a * b << '\n';
            for (int i = 1; i <= a; i++) {
                cnt = (i - 1) % c;
                for (int j = 1; j <= b; j++) {
                    std::cout << i << ' ' << j << ' ' << cnt + 1 << '\n';
                    cnt = (cnt + 1) % c;
                }
            }

        } else if (b * c >= a * b && b * c >= a * c) {
            int cnt = 0;
            std::cout << b * c << '\n';
            for (int i = 1; i <= b; i++) {
                cnt = (i - 1) % a;
                for (int j = 1; j <= c; j++) {
                    std::cout << cnt + 1 << ' ' << i << ' ' << j << '\n';
                    cnt = (cnt + 1) % a;
                }
            }

        } else {
            int cnt = 0;
            std::cout << a * c << '\n';
            for (int i = 1; i <= a; i++) {
                cnt = (i - 1) % b;
                for (int j = 1; j <= c; j++) {
                    std::cout << i << ' ' << cnt + 1 << ' ' << j << '\n';
                    cnt = (cnt + 1) % b;
                }
            }
        }
    }
}
/*
构造题要先知道答案的形式啊

也就是说，将 S 中的所有三元组删去任意一个坐标后，必须得到另外两个坐标的所有可能组合。
这句话看起来很重要，这已经告诉了我们：答案集合的大小是最小应该是 max(a*b，b*c，a*c)
不存在比它更小的：因为如果更小，那么必然存在某一个维度上是不满的

那似乎就有构造的思路了？我注意到样例的构造方案是把最大的那两个坐标排序，然后依次循环填入另一个坐标的升序
而且看着非常正确对不对！
按照那个坐标排序保证了那个平面上一定是满的！另一个循环填入保证了另一个维度也一定是满的！
正确性放生了，脑测正确那就是正确！
这道题看起来是手写spj的挂机题啊！
因为判断答案对不对是非常容易的
*/