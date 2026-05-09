#include <bits/stdc++.h>
using ll = long long;
const int INF = (1 << 29);

int n, c;
std::vector<std::pair<int, ll>> opt;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        char op;
        ll num;
        std::cin >> op >> num;
        switch (op) {
        case '+':
            opt.emplace_back(0, num);
            break;
        case '-':
            opt.emplace_back(1, num);
            break;
        case '*':
            opt.emplace_back(2, num);
            break;
        case '/':
            opt.emplace_back(3, num);
            break;
        }
    }
    std::queue<std::pair<ll, int>> que;
    std::unordered_set<ll> vis;
    auto reans = [&](int d) {
        std::cout << d << '\n';
        exit(0);
    };
    for (que.push({n, 0}); !que.empty();) {
        auto [num, d] = que.front();
        que.pop();
        if (d >= 12)
            break;
        if (vis.count(num))
            continue;
        vis.insert(num);
        for (auto i : opt) {
            auto [op, x] = i;
            switch (op) {
            case 0:
                if (num + x >= INF)
                    break;
                if (num + x == 9)
                    reans(d + 1);
                que.push({num + x, d + 1});
                break;
            case 1:
                if (num - x < 0)
                    break;
                if (num - x == 9)
                    reans(d + 1);
                que.push({num - x, d + 1});
                break;
            case 2:
                if (num * x > INF)
                    break;
                if (num * x == 9)
                    reans(d + 1);
                que.push({num * x, d + 1});
                break;
            case 3:
                if (x == 0)
                    break;
                if (num % x != 0)
                    break;
                if (num / x == 9)
                    reans(d + 1);
                que.push({num / i.second, d + 1});
                break;
            }
        }
    }
    std::cout << "NO" << '\n';
    return 0;
}
// #include <bits/stdc++.h>
// using ll = long long;
// const int INF = (1 << 29);

// int n,c;

// std::vector<std::pair<int,ll> > opt;

// int main(){
//     std::cin.tie(0) -> sync_with_stdio(0);

//     std::cin >> n >> c;
//     for(int i = 1;i <= c;i++) {
//         char op;
//         int num;
//         std::cin >> op >> num;
//         switch (op) {
//             case '+':
//                 opt.emplace_back(0,num);
//                 break;
//             case '-':
//                 opt.emplace_back(1,num);
//                 break;
//             case '*':
//                 opt.emplace_back(2,num);
//                 break;
//             case '/':
//                 opt.emplace_back(3,num);
//                 break;
//         }
//     }
//     auto reans = [&](int d) {
//         std::cout << d << '\n';
//         exit(0);
//     };
//     std::unordered_set<ll> vis;
//     auto dfs = [&](auto& self,ll num,int d,int max_d) -> void {
//         if(num == 9) {
//             std::cout << d << '\n';
//             exit(0);
//         }
//         if(d == max_d) return;
//         for(auto i : opt) {
//             auto [op,x] = i;
//             switch (op) {
//                 case 0:
//                     if(num + x > INF) break;
//                     if(vis.count(num + x)) break;
//                     if(num + x == 9) reans(d + 1);
//                     vis.insert(num + x);
//                     self(self,num + x,d + 1,max_d);
//                     break;
//                 case 1:
//                     if(num - x < 0) break;
//                     if(vis.count(num - x)) break;
//                     if(num - x == 9) reans(d + 1);
//                     vis.insert(num - x);
//                     self(self,num - x,d + 1,max_d);
//                     break;
//                 case 2:
//                     if(num * x > INF) break;
//                     if(vis.count(num * x)) break;
//                     if(num * x == 9) reans(d + 1);
//                     vis.insert(num * x);
//                     self(self,num * x,d + 1,max_d);
//                     break;
//                 case 3:
//                     if(num % x != 0) break;
//                     if(vis.count(num / x)) break;
//                     if(num / x == 9) reans(d + 1);
//                     vis.insert(num / x);
//                     self(self,num / x,d + 1,max_d);
//                     break;
//             }
//         }
//     };
//     for(int i = 1;i <= 12;i++) {
//         vis.clear();
//         dfs(dfs,n,0,i);
//     }
//     std::cout << "NO\n";
//     return 0;
// }