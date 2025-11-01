#include <bits/stdc++.h>

std::unordered_map<std::string,int> vs,vt;
std::queue<std::pair<std::string,int> > qs,qt;
std::string s,t = "123804765";
int dc[4] = {1,3,-1,-3};

bool in(int p,int op) {
    if(op == 0) return p % 3 != 2;
    if(op == 1) return p <= 5;
    if(op == 2) return p % 3 != 0;
    if(op == 3) return p >= 3;
}

void pushs(){
    auto [u,d] = qs.front();
    qs.pop();
    if(vt.count(u)){
        std::cout << d + vt[u] << '\n';
        exit(0);
    }
    for(int i = 0;i < 4;i++){
        std::string to = u;
        int j = 0;
        for(;j < to.size();j++) if(to[j] == '0') break;
        if(in(j,i)){
            std::swap(to[j],to[j + dc[i]]);
            if(!vs.count(to)) qs.push({to,d + 1}),vs[to] = d + 1;
        }
    }
}
void pusht(){
    auto [u,d] = qt.front();
    qt.pop();
    if(vs.count(u)){
        std::cout << vs[u] + d << '\n';
        exit(0);
    }
    for(int i = 0;i < 4;i++){
        std::string to = u;
        int j = 0;
        for(;j < to.size();j++) if(to[j] == '0') break;
        if(in(j,i)){
            std::swap(to[j],to[j + dc[i]]);
            if(!vt.count(to)) qt.push({to,d + 1}),vt[to] = d + 1;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    vs[s] = 0,vt[t] = 0;
    qs.push({s,0}),qt.push({t,0});
    for(;!qs.empty() || !qt.empty();){
        pushs();
        pusht();
    }
    return 0;
}