#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

struct Trie{
    std::unordered_map<char,Trie*> nxt;
    Trie* fail = nullptr; //类比KMP的pi数组
    int cnt = 0;
};
struct ACautomaton{
    Trie* root;

    ACautomaton() {root = new Trie();}
    void insert(std::string &str){
        Trie* p = root;
        for(auto ch : str){
            if(!p->nxt.count(ch))
                p->nxt[ch] = new Trie();
            p = p->nxt[ch];
        }
        p->cnt++;
    }
    void build(){
        std::queue<Trie*> q;
        for(auto [ch,son] : root->nxt)
            son->fail = root, q.push(son);
        while(!q.empty()){
            Trie* cur = q.front();q.pop();
            //类似KMP
            for(auto [ch,son] : cur->nxt){
                Trie* temp = cur->fail;
                //回跳，直到根或者有相同字符
                while(temp != root && !temp->nxt.count(ch)) temp = temp->fail;
                if(temp->nxt.count(ch))
                    son->fail = temp->nxt[ch];
                else
                    son->fail = root;
            }
        }
    }
};

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);


}