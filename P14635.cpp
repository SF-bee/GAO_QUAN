/*
8:35 尝试使用dp求解，但是注意到dp很难记录现在是第几颗糖
9:08 尝试贪心求解，按照 x+y 排序
    买空最便宜的x+y，多余的钱按照x排序购买
    正确性证明：
        反证法，买空如果不买最便宜的 x+y，那答案是不优的
        剩下的钱一定不够再买两颗一样的，按照 x 花完剩下的钱即可
9:23 WA了5，6，7
    主要思路正确，但是可以尝试不买若干个，换成买一个x
9:59 Windows 下 AC 所有样例
10:04 Linux 下 AC 所有样例
AC咯！ *★,°*:.☆(￣▽￣)/$:*.°★* 。
*/
#include <bits/stdc++.h>
using ll = long long;
const int N = 1e5 + 5;
const ll M = 2e4 + 5;

int n;
ll m,ans1,ans2;
struct value{
    ll x,y,id;
    bool operator < (const value &rhs) const {
        if(x + y != rhs.x + rhs.y) return x + y < rhs.x + rhs.y;
        else return y < rhs.y;
    }
}val[N],chan[N];

ll gexval(ll num) {return (num/2)*val[1].x + (num/2)*val[1].y + (num%2)*val[1].y;}

int main() {
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> val[i].x >> val[i].y, val[i].id = i, chan[i] = val[i];
    
    std::sort(val + 1,val + n + 1);
    std::sort(chan + 1,chan + n + 1,[&](const value &lhs,const value &rhs) -> bool {
        return lhs.x < rhs.x;
    });
    ll cp = m / (val[1].x + val[1].y); //买了多少组
    m %= val[1].x + val[1].y;
    ans1 = ans2 = cp * 2;
    ll cho = val[1].id,cnt = 0,turn = 0,res = m; //turn表示要换多少颗,res表示剩下多少钱
    for(int i = 1;i <= n;i++) {
        if(chan[i].id == cho) continue;
        cnt += chan[i].x;
        //剩下的钱够，不用换
        if(cnt <= res) ++ans2;
        //剩下的钱不够，需要换
        else {
            while(cnt > res){
                ++turn;
                --ans2;
                res = m + gexval(turn);
            }
            ++ans2;
        }
        ans1 = std::max(ans1,ans2);
    }
    std::cout << ans1 << '\n';
    return 0;
}