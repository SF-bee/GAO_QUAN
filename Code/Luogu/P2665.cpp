#include <bits/stdc++.h>
#define x first
#define y second

const int MAX = 205;
int n;
std::pair<int,int> p[MAX];
std::set<double> vis;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> p[i].x >> p[i].y;

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            double k;
            if(p[i].x - p[j].x == 0) k = 114514;
            else k = 1.0 * (p[i].y - p[j].y) / (p[i].x - p[j].x);
            // std::cout << k << ' ';
            vis.insert(k);
        }
    }
    std::cout << vis.size();
    return 0;
}