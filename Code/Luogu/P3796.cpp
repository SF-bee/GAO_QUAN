#include <bits/stdc++.h>
const int N = 2e2 + 5;
const int M = 2e4 + 5;
const int C_SIZE = 26;

int n,ans[N];
std::string mode[N],text;
struct Trie{
    int fail,nxt[C_SIZE];
    int end,id;
    Trie() : fail(0),end(0),id(0) {std::memset(nxt,0,sizeof(nxt));}
};
struct ACautomaton{
    Trie root[M];
    int cnt = 0;
    int gnum(char &ch) {return ch - 'a';}
    void insert(std::string &str,int id){
        int p = 0;
        for(auto ch : str){
            int c = gnum(ch);
            if(!root[p].nxt[c])
                root[p].nxt[c] = ++cnt;
            p = root[p].nxt[c];
        }
        root[p].end++;
        root[p].id = id;
    }
    void build(){
        std::queue<int> q;
        for(int i = 0;i < C_SIZE;i++) 
            if(root[0].nxt[i])
                q.push(root[0].nxt[i]);
        while(!q.empty()){
            int cur = q.front();q.pop();
            for(int i = 0;i < C_SIZE;i++){
                if(root[cur].nxt[i]){
                    root[root[cur].nxt[i]].fail = root[root[cur].fail].nxt[i];
                    q.push(root[cur].nxt[i]);
                }
                else root[cur].nxt[i] = root[root[cur].fail].nxt[i];
            }
        }
    }
    void query(std::string &str){
        int p = 0;
        for(auto ch : str){
            p = root[p].nxt[gnum(ch)];
            for(int t = p;t;t = root[t].fail){
                if(root[t].end > 0)
                    ans[root[t].id]++;
            }
        }
    }
};

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    while(true){
        std::memset(ans,0,sizeof(ans));
        std::cin >> n;
        if(n == 0) return 0;
        ACautomaton AC;
        for(int i = 1;i <= n;i++){
            std::cin >> mode[i];
            AC.insert(mode[i],i);
        }
        std::cin >> text;
        AC.build();
        AC.query(text);
        int mans = *std::max_element(ans + 1,ans + n + 1);
        std::cout << mans << '\n';
        for(int i = 1;i <= n;i++)
            if(ans[i] == mans) std::cout << mode[i] << '\n';
    }
    return 0;
}