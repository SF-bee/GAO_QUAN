#include <bits/stdc++.h>

const int MAX = 1000005;
const int N = 2005;
int a[MAX];
int pa[N];
int n,m,al,ar;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> a[i];

    int l = 1,r = 1,num = 0,ans = MAX;
    while(l <= r && r <= n + 1){
        if(num < m){
            r++;
            if(pa[a[r - 1]] == 0) num++;
            pa[a[r - 1]]++;
        }
        else{
            if(ans > r - l){
                al = l;
                ar = r - 1;
                ans = r - l;
            }
            if(pa[a[l]] - 1 == 0) num--;
            pa[a[l]]--;
            l++;
        }
    }
    std::cout << al << " " << ar;
    return 0;
}