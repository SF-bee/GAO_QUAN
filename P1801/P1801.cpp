#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int m,n,a[MAX],u[MAX];
struct bb{
    int i;
    std::priority_queue<int> pre;
    std::priority_queue<int,std::vector<int>,std::greater<int> > nxt;
    
    bb(){i = 0;}
    int get(){
        i++;
        while(pre.size() < i - 1) pre.push(nxt.top()),nxt.pop();
        return nxt.top();
    }
    void add(int x){
        if(pre.size() == 0 || x > pre.top()) nxt.push(x);
        else{
            nxt.push(pre.top());
            pre.pop();
            pre.push(x);
        }
    }
}box;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m >> n;
    for(int i = 1;i <= m;i++) std::cin >> a[i];
    for(int i = 1;i <= n;i++) std::cin >> u[i];
    for(int i = 1,j = 1;i <= m;i++){
        if(u[j] == i){
            box.add(a[i]);
            while(u[j] == i) std::cout << box.get() << '\n',j++;
        }
        else box.add(a[i]);
    }
    return 0;
}