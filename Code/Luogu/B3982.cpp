#include <bits/stdc++.h>

const int MAX = 1e2 + 5;
int n,m;
std::vector<std::string> key;  //关键字
std::vector<std::pair<std::string,bool> > ord;  //关键字排序方式，0为小到大
std::map<std::string,std::string> a[MAX];
bool check(const std::string s){  //判断是否是数字
    for(auto i : s)
        if('0' > i || i > '9') return 0;
    return 1;
}
int change(const std::string s){  //字符串变数字
    int res = 0;
    for(auto i : s)
        res = res * 10 + (i - '0');
    return res;
}
bool cmp(std::map<std::string,std::string> x,std::map<std::string,std::string> y){
    for(auto [ky,od] : ord){  //遍历排序方式
        if(x[ky] == y[ky]) continue;  //相同则使用下一种方式
        if(check(x[ky]) && check(y[ky]))  //是数字按数字排
            return (od ? change(x[ky]) > change(y[ky]) : change(x[ky]) < change(y[ky]));
        else  //否则按字典排
            return (od ? x[ky] > y[ky] : x[ky] < y[ky]);
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string t,input;
    std::cin >> n;
    std::getline(std::cin,input);
    std::getline(std::cin,input);
    for(auto i : input){
        if(i == ',') key.push_back(t),t = "";
        else t += i;
    }
    key.push_back(t),t = "";
    for(int i = 0;i < n - 1;i++){
        std::getline(std::cin,input);
        int cnt = 0;
        for(auto j : input){
            if(j == ',') a[i][key[cnt++]] = t,t = "";
            else t += j;
        }
        a[i][key[cnt++]] = t,t = "";
    }
    std::cin >> m;
    std::getline(std::cin,input);
    for(int i = 0;i < m;i++){
        std::getline(std::cin,input);
        for(auto j : input){
            if(j == '+' || j == '-') ord.push_back({t,(j == '+' ? 0 : 1)}),t = "";
            else t += j;
        }
    }
    std::stable_sort(a,a + n - 1,cmp);
    for(int j = 0;j < key.size();j++){
        std::cout << key[j] << ",\n"[j == key.size() - 1];
    }
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < key.size();j++){
            std::cout << a[i][key[j]] << ",\n"[j == key.size() - 1];
        }
    }
    return 0;
}