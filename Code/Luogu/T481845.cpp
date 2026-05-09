#include <bits/stdc++.h>

const int MAX = 1e5 + 5;
int n,q;
std::vector<int> cab[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    while(q--){
        int op,i,j,k;
        std::cin >> op >> i >> j;
        switch (op){
            case 1:
                std::cin >> k;
                if(cab[i].size() <= j) cab[i].resize(j + 1);
                cab[i].at(j) = k;
                break;
            case 2:
                std::cout << cab[i][j] << '\n';
                break;
        }
    }
    return 0;
}