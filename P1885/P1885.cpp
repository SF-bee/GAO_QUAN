#include <bits/stdc++.h>
const int MAX = 5e5;

int n;
int f[MAX];

char fun(int x,int k){
    if(k == 0){
        switch (x){
            case 1: return 'm';
            case 2: return 'o';
            case 3: return 'o';
        }
    }
    if(x <= f[k - 1]) return fun(x,k - 1);
    if(x > f[k] - f[k - 1]) return fun(x - f[k] + f[k - 1],k - 1);
    if(x == f[k - 1] + 1) return 'm';
    return 'o';
}

int main(){
    scanf("%d",&n);
    f[0] = 3;
    int k = 0;
    while(f[k] < n){
        k++;
        f[k] = f[k - 1] * 2 + k + 3;
    }
    putchar(fun(n,k));
    return 0;
}