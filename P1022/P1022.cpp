#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);;

    char c,s; //c为当前读入的字符，s为未知数
    int k = 0,b = 0,num = 0;
    int f = 1, eq = 1;
    bool r = 0;
    while(std::cin >> c){
        if(c == '+'){
            b += eq * f * num;
            num = 0;
            f = 1;
            r = 0;
        }
        else if(c == '-'){
            b += eq * f * num;
            num = 0;
            f = -1;
            r = 0;
        }
        else if(c == '='){
            b += eq * f * num;
            num = 0;
            f = 1;
            eq = -1;
            r = 0;
        }
        else if(c >= '0' && c <= '9')
            num = num * 10 + (c - '0'),r = 1;
        else if(c >= 'a' && c <= 'z'){
            r ?
                k += eq * f * num :
                k += eq * f;
            num = 0;
            s = c;
            r = 0;
        }
    }
    b += eq * f * num;
    double ans = 1.0 * -b / k;
    if(ans == -0.0) ans = 0;
    std::cout << s << '=' << std::fixed << std::setprecision(3) << ans << '\n'; 
    return 0;
}