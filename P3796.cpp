#include <bits/stdc++.h>
const int M = 2e4 + 5;
const int C_SIZE = 26;
const int MAX = 1e6 + 5;

struct Trie{
    int fail,nxt[C_SIZE];
    int end;
    Trie() : fail(0),end(0) {std::memset(nxt,0,sizeof(nxt));}
};
struct ACautomaton{
    Trie root[M];
    int cnt = 0;
    int gnum(char &ch) {return ch - 'a';}
    void insert(std::string &str){
        int p = 0;
        for(auto ch : str){
            if(root[p].nxt[gnum(ch)])
                root[p].nxt[gnum(ch)] = ++cnt;
            p = root[p].nxt[gnum(ch)];
        }
        root[p].end++;
    }
    void build(){
        std::queue<int> q;
        for(int i = 0;i < C_SIZE;i++) if(root[0].nxt[i])
            q.push(root[0].nxt[i]);
        while(!q.empty()){
            int p = q.front();q.pop();
        }
    }
};

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    return 0;
}