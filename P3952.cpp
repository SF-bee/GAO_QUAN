#include <bits/stdc++.h>
const int MAX = 200;

int t;
struct rep { //表示一个循环体
    std::string i,x,y;
    bool check() { //判断这个循环的数量级,0表示O 1,1表示O n
        if(y != "n") return 0;
        else return 1;
    }
};

int get_tc(std::string &_tc) { //返回时间复杂度的次数
    auto pos = _tc.find('^');
    if(pos == std::string::npos) return 0;
    return std::stoi(_tc.substr(pos + 1,_tc.find(')') - pos - 1));
}
void solve() {
    int l,w;
    std::string tc;
    std::cin >> l >> tc;
    w = get_tc(tc);

    int tim = 0,ntim = 0; //当前复杂度数量级
    std::stack<rep> rpls;
    std::unordered_set<std::string> vis; //表示当前定义域内已经声明的变量
    bool cannot = 0,err = 0; //表示从当前开始的循环都无法进入
    for(int i = 1;i <= l;i++){
        char op;
        rep in;
        std::cin >> op;
        switch (op){
            case 'F':
                std::cin >> in.i >> in.x >> in.y;
                if(err) break;
                if(vis.find(in.i) != 0){
                    err = 1;
                    break;
                }
                if(cannot) break;
                if(in.check()) ntim++;
                else cannot = 1;
                vis.insert(in.i);
                rpls.push(in);
                break;
            case 'E':
                if(!rpls.top().check()) cannot = 0,ntim++;
                rpls.pop();
                ntim--;
                break;
        }
        tim = std::max(tim,ntim);
    }
    if(err || !rpls.empty()) std::cout << "ERR\n";
    else if(tim == w) std::cout << "Yes\n";
    else std::cout << "No\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}