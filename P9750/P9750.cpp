#include <bits/stdc++.h>

int t,m;

inline int delta(int a,int b,int c){return b * b - 4 * a * c;}

std::pair<int,int> sim(int x){
    int a = 1;
    for(int i = 2;i * i <= x;i++)
        while(x % (i * i) == 0)
            a *= i,x /= (i * i);
    return {(a == 0 ? 1 : a),x};
}

std::pair<int,int> red(int a,int b){
    int t = std::abs(a);
    int d = std::__gcd(t,b);
    t /= d,b /= d;
    if(a < 0) return {-t,b};
    else return {t,b};
}

int main(){
    scanf("%d %d",&t,&m);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a < 0) a = -a,b = -b,c = -c;
        if(delta(a,b,c) < 0){
            printf("NO\n");
            continue;
        }
        auto [s1,s2] = sim(delta(a,b,c));
        auto [a1,b1] = red(-b,2 * a);
        auto [a2,b2] = red(s1,2 * a);
        if(s2 <= 1){
            a2 *= s2;
            int nb = b1 * b2 / std::__gcd(abs(b1),b2);
            a1 = a1 * (nb / b1);
            a2 = a2 * (nb / b2);
            int na = a1 + a2;
            auto [ea,eb] = red(na,nb);
            if(ea == 0) printf("%d",0);
            else if(eb == 1) printf("%d",ea);
            else printf("%d/%d",ea,eb);
        }
        else{
            if(a1 != 0){
                if(b1 == 1) printf("%d+",a1);
                else printf("%d/%d+",a1,b1);
            }
            if(a2 == 1) printf("sqrt(%d)",s2);
            else printf("%d*sqrt(%d)",a2,s2);
            if(b2 != 1) printf("/%d",b2);
        }
        printf("\n");
    }
    return 0;
}