#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

struct Trie{
    std::unordered_map<char,Trie*> son;
    Trie* fail = nullptr;
    int cnt = 0;
};
struct ACautomaton{
    Trie* root;

    ACautomaton() {root = new Trie();}
    void insert(std::string &str){
        Trie* p = root;
        for(auto ch : str){
            if(!p->son.count(ch))
                p->son[ch] = new Trie();
            p = p->son[ch];
        }
        p->cnt++;
    }
    void build(){
        std::queue<Trie*> q;
        for(auto [ch,son] : root->son)
            son->fail = root, q.push(son);
    }
};

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);


}