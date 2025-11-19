#include <bits/stdc++.h>
const int MAX = 1e6 + 5;
const int C_SIZE = 30;

struct Trie{
    int nxt[C_SIZE],fail;
    int end = 0;
}root[MAX];
int cnt;
int gid(char &ch) {return ch - 'a';}
void insert(std::string &str){
    int p = 0;
    for(auto ch : str){
        if(!root[p].nxt[gid(ch)])
            root[p].nxt[gid(ch)] = ++cnt;
        p = root[p].nxt[gid(ch)];
    }
    root[p].end++;
}
void build(){
    std::queue<int> q;
    for(int i = 0;i < 26;i++) if(root[0].nxt[i]){
        root[root[0].nxt[i]].fail = 0;
        q.push(root[0].nxt[i]);
    }
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int i = 0;i < 26;i++){
            if(root[cur].nxt[i]){
                root[root[cur].nxt[i]].fail = root[root[cur].fail].nxt[i];
                q.push(root[cur].nxt[i]);
            }
            else root[cur].nxt[i] = root[root[cur].fail].nxt[i];
        }
    }
}
int query(std::string &str){
    int ans = 0,p = 0;
    for(auto ch : str){
        p = root[p].nxt[gid(ch)];
        for(int t = p;t && root[t].end != -1;t = root[t].fail){
            ans += root[t].end;
            root[t].end = -1;
        }
    }
    return ans;
}
int n;
std::string text;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    std::string mode;
    for(int i = 1;i <= n;i++){
        std::cin >> mode;
        insert(mode);
    }
    build();
    std::cin >> text;
    std::cout << query(text);
}