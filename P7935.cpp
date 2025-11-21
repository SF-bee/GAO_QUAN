#include <bits/stdc++.h>

const int MAX = 100005;
int n,sum;
int a1[MAX],a2[MAX],a3[MAX];
int c1[MAX],c2[MAX],c3[MAX];
int t[MAX];
std::queue<int> q;

int main(){
    // freopen("a.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++) std::cin >> a1[i],c1[a1[i]]++,t[a1[i]] = i;
    for(int i = 0;i < n;i++) std::cin >> a2[i],c2[a2[i]]++;
    for(int i = 0;i < n;i++) std::cin >> a3[i],c3[a3[i]]++;
    
    for(int i = 1;i <= n;i++){
        if(c2[i] == 0) q.push(i);
        if(c3[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(t[p] == 0) continue;
        c2[a2[t[p]]]--;
        c3[a3[t[p]]]--;
        sum++;
        if(c2[a2[t[p]]] == 0) q.push(a2[t[p]]);
        if(c3[a3[t[p]]] == 0) q.push(a3[t[p]]);
        t[p] = 0;
    }

    std::cout << sum;
    return 0;
}