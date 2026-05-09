#include <bits/stdc++.h>

struct node{
    int a,b,c,i,t;
    bool operator < (const node &rhs) const{
        if(a + b + c != rhs.a + rhs.b + rhs.c) return a + b + c > rhs.a + rhs.b + rhs.c;
        else if(a + b != rhs.a + rhs.b) return a + b > rhs.a + rhs.b;
        else if(std::max(a,b) != std::max(rhs.a,rhs.b)) return std::max(a,b) > std::max(rhs.a,rhs.b);
    }
    bool operator == (const node &rhs) const{
        if(a + b + c == rhs.a + rhs.b + rhs.c && a + b == rhs.a + rhs.b && std::max(a,b) == std::max(rhs.a,rhs.b))
            return 1;
        else
            return 0;
    }
};
const int MAX = 1e4 + 5;
int n;
std::array<node,MAX> arr;

inline bool comp(node x,node y){return x.i < y.i;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].i = i;
    };
    std::sort(arr.begin() + 1,arr.begin() + n + 1);
    
    for(int i = 1;i <= n;i++) arr[i].t = i;
    for(int i = 1;i <= n;i++){
        if(arr[i] == arr[i - 1]){
            arr[i].t = arr[i - 1].t;
        }    
    }
    std::sort(arr.begin() + 1,arr.begin() + n + 1,comp);
    for(int i = 1;i <= n;i++)
        std::cout << arr[i].t << '\n';
    return 0;
}