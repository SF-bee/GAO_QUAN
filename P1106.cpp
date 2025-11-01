#include <bits/stdc++.h>

int k;
std::string num;

int main(){
    std::cin >> num >> k;
    if(num.size() == k){
        std::cout << 0 << '\n';
        return 0;
    }
    while(k){
        bool flag = 0;
        for(int j = 0;j < num.size();j++)
            if(j + 1 < num.size() && num[j] > num[j + 1]){
                num.erase(j,1);
                flag = 1;
                k--;
                break;
            }
        if(!flag) break;
    }
    if(k != 0) num.erase(num.size() - k);
    int i = 0;
    for(;i < num.size() && num[i] == '0';i++);
    if(i == num.size()){
        std::cout << 0;
        return 0;
    }
    num.erase(0,i);
    std::cout << num << '\n';
    return 0;
}