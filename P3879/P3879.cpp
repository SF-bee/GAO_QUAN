#include <bits/stdc++.h>
const int MAXN = 1e3 + 5;
const int MAX = 5e3 + 5;

inline int gnum(char ch){return ch - 'a';}

struct node{
    int trie[MAX][26],tot = 0;
    bool word[MAX];

    void insert(std::string ch){
        int u = 0;
        for(auto i : ch){
            int a = gnum(i);
            if(trie[u][a] == 0) trie[u][a] = ++tot;
            u = trie[u][a];
        }
        word[u] = true;
    }

    bool find(std::string ch){
        int u = 0;
        for(auto i : ch){
            int a = gnum(i);
            if(trie[u][a] == 0) return false;
            u = trie[u][a];
        }
        return word[u];
    }
}a[MAXN];

int n,m,l;
std::string ch;
long double a;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> l;
        for(int j = 1;j <= l;j++){
            std::cin >> ch;
            a[i].insert(ch);
        }
    }

    std::cin >> m;
    for(int i = 1;i <= m;i++){
        std::cin >> ch;
        for(int j = 1;j <= n;j++) if(a[j].find(ch))
            std::cout << j << ' ';
        std::cout << '\n';
    }
    return 0;
}