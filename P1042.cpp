#include <bits/stdc++.h>

std::string s;

void read(){
    std::string c;
    while(std::cin >> c){
        bool flag = 0;
        for(auto i : c){
            if(i != 'E') s += i;
            else{
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
}

bool check(int x,int w,int l){
    if(abs(w - l) >= 2 && (w >= x || l >= x)) return true;
    else return false;
}

void s11(){
    int sumW = 0,sumL = 0;
    for(auto i = s.begin();i != s.end();i++){
        if(*i == 'W') ++sumW;
        else ++sumL;

        if(check(11,sumW,sumL)){
            std::cout << sumW << ':' << sumL << '\n';
            sumW = sumL = 0;
        }
    }
    std::cout << sumW << ':' << sumL << '\n';
}

void s21(){
    int sumW = 0,sumL = 0;
    for(auto i = s.begin();i != s.end();i++){
        if(*i == 'W') ++sumW;
        else ++sumL;

        if(check(21,sumW,sumL)){
            std::cout << sumW << ':' << sumL << '\n';
            sumW = sumL = 0;
        }
    }
    std::cout << sumW << ':' << sumL << '\n';
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("P1042.in","r",stdin);
        freopen("P1042.out","w",stdout);
    #endif
    read();
    s11();
    std::cout << '\n';
    s21();
    return 0;
}