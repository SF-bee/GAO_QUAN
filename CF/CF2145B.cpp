#include <bits/stdc++.h>

int T;
int n,k;
std::string s;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> n >> k >> s;
        std::string ans;
        for(int i = 0;i < n;i++)
            ans += "+";
        int l = 0,r = n - 1;    
        for(auto i : s){
            switch (i - '0'){
                case 0:
                    ans[l++] = '-';
                    break;
                case 1:

                    break;
                case 2:

                    break;
            }
        }
    }
    return 0;
}