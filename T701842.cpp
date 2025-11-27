#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

std::string tx,md;
int fail[MAX];

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> tx >> md;
    for(int j = 0,i = 1;i < md.size();i++){
        while(j && md[j] != md[i]) j = fail[j - 1];
        if(md[i] == md[j]) j++;
        fail[i] = j;
    }
    for(int i = 0,j = 0;i < tx.size();i++){
        if(tx[i] == md[j]) j++;
        else {
            while(j && tx[i] != md[j]) j = fail[j - 1];
            if(tx[i] == md[j]) j++;
        }
        if(j == md.size()){
            std::cout << i - md.size() + 2 << '\n';
            j = fail[j - 1];
        }
    }
    for(int i = 0;i < md.size();i++) std::cout << fail[i] << (i + 1 == md.size() ? '\n' : ' ');
    return 0;
}