#include <bits/stdc++.h>

int n,a,k;
std::string at;
std::set<std::string> s;
std::set<int> ans;

char change(char x,bool op){
    if(op){
        if(x == '9') x = '0';
        else x = (char)(x + 1);
    }
    else{
        if(x == '0') x = '9';
        else x = (char)(x - 1);
    }
    return x;
}

void dfs(int d,int cnt,std::string now){
    if(cnt == k) return;
    if(d == n) return;
    dfs(d + 1,cnt,now);
    std::string t = now;
    t[d] = change(now[d],1);
    if(s.count(t) == 0){
        s.insert(t);
        dfs(d + 1,cnt + 1,t);
    }
    t[d] = change(now[d],0);
    if(s.count(t) == 0){
        s.insert(t);
        dfs(d + 1,cnt + 1,t);
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n >> a >> k;
    while(a)
        at += (a % 10) + '0',a /= 10;
    for(int i = at.size();i < n;i++)
        at += '0';
    s.insert(at);
    dfs(0,0,at);
    for(auto i : s){
        int t = 0;
        for(auto j = i.rbegin();j != i.rend();j++)
            t = t * 10 + ((*j) - '0');
        ans.insert(t);
    }
    for(auto i : ans)
        std::cout << i << '\n';
    return 0;
}