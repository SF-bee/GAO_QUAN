#include <bits/stdc++.h>
const int MAX = 80;

inline int id(char ch){
    return ch - 'a';
}
int n,ans;
std::string s;
struct node{
    int trie[MAX][26];
    int word[MAX];
    int tot;
    void insert(std::string s){
        int u = 0,res = 0;
        for(auto i : s){
            int a = id(i);
            if(trie[u][a] == 0) trie[u][a] = ++tot;
            u = trie[u][a];
            res += word[u];
        }
        word[u]++;
        ans = std::max(res + 1,ans);
    }
}tree;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::cin >> s;
        tree.insert(s);
    }
    std::cout << ans;
    return 0;
}