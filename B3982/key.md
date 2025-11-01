# [B3982 [信息与未来 2024] 数据排序](https://www.luogu.com.cn/problem/B3982) 题解

本题主要考察对于自定义比较函数的使用与对整行字符串的处理。难点在于如何正确处理整行的字符串。

### 1、处理输入的字符串

* 对于输入的整行字符串，我们可以使用 `std::getline()` 来进行输入。

* 读入后，我们可以遍历读入整个字符串，以 `,` 为分隔把单个字符串使用数组存储下来。

```cpp
std::string t,input;
std::vector<std::string> key;
std::getline(std::cin,input);
for(auto i : input){
    if(i == ',') key.push_back(t),t = "";  //一定不要忘了清空
    else t += i;
}
key.push_back(t),t = "";  //因为最后一段没有逗号结尾，所以需要手动添加
```

* 需要注意的是，使用 `std::cin` 进行输入后，需要先进行一次 `std::getline()` 才能进行后续的操作，这是因为使用 `std::cin` 读入后，行末会遗留一个换行符，直接使用 `std::getline()` 会导致读入空行的情况。

* 对于表格正文内容，我们可以使用 map 进行存储，map 的每个元素由一个 key 和一个 val 组成，正好对应题目表头与内容的关系。

```cpp
std::map<std::string,std::string> a[MAX];
for(int i = 0;i < n - 1;i++){
    std::getline(std::cin,input);
    int cnt = 0;
    for(auto j : input){
        if(j == ',') a[i][key[cnt++]] = t,t = "";
        else t += j;
    }
    a[i][key[cnt++]] = t,t = "";
}
```

* 而对于排序规则，我们可以使用一个类型为 `std::pair<std::string,bool>` 的数组进行存储。其中，第一项为关键字，第二项为排序方式，0 代表从小到大，1 表示从大到小。

```cpp
std::vector<std::pair<std::string,bool> > ord;
std::cin >> m;
std::getline(std::cin,input);
for(int i = 0;i < m;i++){
    std::getline(std::cin,input);
    for(auto j : input){
        if(j == '+' || j == '-') ord.push_back({t,(j == '+' ? 0 : 1)}),t = "";
        else t += j;
    }
}
```

### 2、进行排序

* map 本身的排序方式并不能满足我们的需求，因此我们需要自定义比较函数。

* 我们遍历整个排序规则，如果比较的两项对应关键字的值不同，我们就进行比较。特别的，我们需要对关键字进行判断是否为数字，如果是数字则需要先转为数字再比较。

```cpp
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
```

* 最后，我们应该使用 `std::stable_sort()`。因为 `std::sort()` 是不稳定的。

### 输出

* 输出排完序后的 map 即可，注意判断最后一个元素不需要加逗号。

### AC code

```cpp
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
```