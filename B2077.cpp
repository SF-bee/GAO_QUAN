#include <bits/stdc++.h>

int main(){
    long long n;
    scanf("%d",&n);
    while(n != 1){
        if(n % 2 != 0){
            printf("%d*3+1=%d\n",n,n * 3 + 1);
            n = n * 3 + 1;
        }
        else if(n % 2 == 0){
            printf("%d/2=%d\n",n,n / 2);
            n = n / 2;
        }
    }
    printf("end\n");
    return 0;
}