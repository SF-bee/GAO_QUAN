#include <bits/stdc++.h>
typedef unsigned long long ull;
const int MAX = 1e5 + 5;
const int base = 13331;

int t,n,m;
ull h1[MAX],h2[MAX],b[MAX];
std::string s1,s2;

bool check(int l1,int r1,int l2,int r2){
    int x = h1[r1] - h1[l1 - 1] * b[r1 - l1 + 1];
    int y = h2[r2] - h2[l2 - 1] * b[r2 - l2 + 1];
    return x == y;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> t;
    while(t--){
        std::cin >> n >> m;
        std::cin >> s1 >> s2;
        for(int i = 0;i < n;i++){
            if(i == 0) h1[i] = s1[i];
            else h1[i] = h1[i - 1] * base + s1[i];
        }
        for(int i = 0;i < m;i++){
            if(i == 0) h2[i] = s2[i],b[i] = 1;
            else{
                h2[i] = h2[i - 1] * base + s2[i];
                b[i] = b[i - 1] * base;
            }
        }
        //开头插入
        if(check(0,n - 1,m - n,m - 1)) std::cout << "Yes\n";
        else{
            bool flag = 0;
            for(int i = 0;i < n;i++){
                if(check(0,i,0,i) && check(i + 1,n - 1,m - n + i + 1,m - 1)){
                    flag = 1;
                    break;
                }
            }
            std::cout << (flag ? "Yes\n" : "No\n");
        }
    }
    return 0;
}