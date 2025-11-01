#include <bits/stdc++.h>
int T;
int rd() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int main(){
    T = rd();
    while(T--){
        int n;
        bool flag = 0;
        n = rd();
        while(n--){
            int i = rd();
            if(i == 0)
                flag = 1;
        }
        if(flag) puts("yes");
        if(!flag) puts("no");
    }
    return 0;
}