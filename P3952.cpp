#include <bits/stdc++.h>
const int MAX = 200;

int t;
struct rep { //表示一个循环体
    std::string i; //变量名
    bool act,is_n; //act表示可以进入循环，is_n表示是否是On的循环
    void init(std::string &num,std::string &x,std::string &y) {
        i = num;
        if(x == "n" && y == "n") act = true,is_n = false;
        else if(x == "n" && y != "n") act = false,is_n = false;
        else if(x != "n" && y == "n") act = true,is_n = true;
        else{
            int _x = std::stoi(x),_y = std::stoi(y);
            act = (_x <= _y);
            is_n = false;
        }
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
    bool inact = 0,err = 0; //inact表示是否在在有效循环中，err表示存在语法错误
    for(int i = 1;i <= l;i++){
        char op;
        std::string num,x,y;
        rep in;
        std::cin >> op;
        switch (op){
            case 'F':
                std::cin >> num >> x >> y;
                in.init(num,x,y);
                if(vis.count(in.i)) err = 1;
                vis.insert(in.i);
                if(!in.act || !inact) {
                    inact = 0;
                    in.act = 0;
                }
                else if(in.is_n) tim++;
                ntim = std::max(ntim,tim);
                rpls.push(in);
                break;
            case 'E':
                if(rpls.empty()) err = 1;
                else {
                    auto [i,act,is_n] = rpls.top();
                    rpls.pop();
                    if(is_n) tim--;
                    if(!act) {
                        if(rpls.empty() || rpls.top().act)
                            inact = true;
                    }
                }
                break;
        }
    }
    if(err || !rpls.empty()) std::cout << "ERR\n";
    else if(ntim == w) std::cout << "Yes\n";
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