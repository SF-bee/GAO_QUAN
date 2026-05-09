#include <bits/stdc++.h>

std::string x,y;
std::vector<int> a,b;

//输出
void output(std::vector<int> a){
    for(auto i = a.begin();i < a.end();i++)
        std::cout << *i;
    std::cout << '\n';
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> x >> y;
    for(int i = 0;i < x.size();i++)
        a.push_back(x[i] - '0'),b.push_back(y[i] - '0');
    for(int i = 0;i < a.size() - 1;i++){  //每个位置枚举
        if(a[i] != b[i]){
            int j = i + 1;
            while (j < a.size() && a[j] == b[j]) j++;
            if(a[i] * a[j] + b[i] * b[j] > a[i] * b[j] + b[i] * a[j]){
                std::swap(a[i],b[i]);
                i = j;
            }
        }
    }
    output(a);
    output(b);
    return 0;
}