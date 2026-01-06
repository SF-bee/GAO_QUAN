#include <bits/stdc++.h>
const int MAX = 200;

int t;
int l;
std::string tc;
struct rep { //表示一个循环体
    std::string i,x,y;
}r[MAX];
std::unordered_set<std::string> vis; //表示当前定义域内已经声明的变量

int get_tc(std::string &_tc) { //返回时间复杂度的次数
    auto pos = _tc.find('^');
    if(pos == std::string::npos) return 0;
    return std::stoi(tc.substr(pos + 1,_tc.find(')') - pos - 1));
}
void solve() {
    std::cin >> l >> tc;
    int w = get_tc(tc);
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}