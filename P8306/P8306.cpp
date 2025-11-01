#include <bits/stdc++.h>
const int MAX = 3e6 + 5;

int ga(char c){
    if('a' <= c && c <= 'z') return c - 'a';
    else if('A' <= c && c <= 'Z') return c - 'A' + 26;
    else return c - '0' + 52;
}

struct node{
    int trie[MAX][65];
    int vis[MAX];
    int cnt = 0;

    void clear(){
        for(int i = 0;i <= cnt;i++){
            vis[i] = 0;
            for(int j = 0;j <= 65;j++){
                trie[i][j] = 0;
            }
        }
        cnt = 0;
    }

    void insert(std::string ch){
        int u = 0;
        for(auto i : ch){
            int c = ga(i);
            if(trie[u][c] == 0)
                trie[u][c] = ++cnt;
            u = trie[u][c];
            vis[u]++;
        }
    }

    int find(std::string ch){
        int u = 0;
        for(auto i : ch){
            int c = ga(i);
            if(trie[u][c] == 0)
                return 0;
            u = trie[u][c];
        }
        return vis[u]; 
    }
}a;

int T;
int n,q;
std::string s;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> n >> q;
        a.clear();
        for(int i = 0;i < n;i++){
            std::cin >> s;
            a.insert(s);
        }
        for(int i = 0;i < q;i++){
            std::cin >> s;
            std::cout << a.find(s) << '\n';
        }
    }
    return 0;
}