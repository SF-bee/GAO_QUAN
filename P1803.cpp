#include <bits/stdc++.h>

struct node{
    int a,b;
    bool operator < (const node &rhs) const{
        return b < rhs.b;
    }
};
const int MAX = 1e5+5;
int n,ans = 1;
node arr[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++) std::cin >> arr[i].a >> arr[i].b;
    
    std::sort(arr,arr + n);
    int now = arr[0].b;
    for(int i = 1;i < n;i++){
        if(arr[i].a >= now){
            now = arr[i].b;
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}