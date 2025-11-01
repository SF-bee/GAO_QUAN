#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,cnt_max[10],cnt_now[10];  //cnt_max[i] 存储 i 运动最多可以连续多少天 cnt_now[i] 存储 i 运动当前连续了多少天
int px,py;  //px,py分别表示昨天的x,y

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        int x,y;
        std::cin >> x >> y;
        if(x == y) y = 0;
        //如果今天的运动可以接上昨天的运动，增加连续天数，否则重新开始计数
        if(x == px || x == py) cnt_now[x]++,cnt_max[x] = std::max(cnt_max[x],cnt_now[x]);
        else cnt_now[x] = 1,cnt_max[x] = std::max(cnt_max[x],cnt_now[x]);
        if(y == px || y == py) cnt_now[y]++,cnt_max[y] = std::max(cnt_max[y],cnt_now[y]);
        else cnt_now[y] = 1,cnt_max[y] = std::max(cnt_max[y],cnt_now[y]);
        //同时将之前的计数归零
        if(px != x && px != y) cnt_now[px] = 0;
        if(py != x && py != y) cnt_now[py] = 0;
        px = x;
        py = y;
    }
    int mxid = 0;  //取连续天数最多的运动
    for(int i = 1;i < 10;i++)  //在所有类型的运动中取最大值
        if(cnt_max[i] > cnt_max[mxid]) 
            mxid = i;
    std::cout << cnt_max[mxid] << ' ' << mxid << '\n';
    return 0;
}