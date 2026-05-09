#include <bits/stdc++.h>
const int MAX = 300;

int W,I,G,B;
bool mp[5][5][5]; //mp[i][j]表示i和j可以组成的字母
std::string s;
bool dp[MAX][MAX][5]; //dp[l][r][i]表示l到r区间是否可以被i替代

int change(char ch){
    if(ch == 'W') return 1;
    if(ch == 'I') return 2;
    if(ch == 'N') return 3;
    if(ch == 'G') return 4;
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> W >> I >> G >> B;
    for(int i = 1;i <= W;i++){
        std::string ch;
        std::cin >> ch;
        mp[change(ch[0])][change(ch[1])][1] = 1;
    }
    for(int i = 1;i <= I;i++){
        std::string ch;
        std::cin >> ch;
        mp[change(ch[0])][change(ch[1])][2] = 1;
    }
    for(int i = 1;i <= G;i++){
        std::string ch;
        std::cin >> ch;
        mp[change(ch[0])][change(ch[1])][3] = 1;
    }
    for(int i = 1;i <= B;i++){
        std::string ch;
        std::cin >> ch;
        mp[change(ch[0])][change(ch[1])][4] = 1;
    }
    std::cin >> s;
    for(int i = 0;i < s.size();i++)
        dp[i][i][change(s[i])] = 1;
    for(int i = 1;i < s.size();i++){
        for(int l = 0;l < s.size() - i;l++){
            int r = l + i;
            for(int k = l;k <= r;k++){
                for(int x = 1;x <= 4;x++){
                    for(int y = 1;y <= 4;y++)
                        for(int z = 1;z <= 4;z++)
                            if(mp[x][y][z] &&  dp[l][k][x] && dp[k + 1][r][y]){
                                    dp[l][r][z] = 1;
                            }
                }
            }
        }
    }
    bool flag = 0;
    if(dp[0][s.size() - 1][1]) std::cout << "W",flag = 1;
    if(dp[0][s.size() - 1][2]) std::cout << "I",flag = 1;
    if(dp[0][s.size() - 1][3]) std::cout << "N",flag = 1;
    if(dp[0][s.size() - 1][4]) std::cout << "G",flag = 1;
    if(!flag) std::cout << "The name is wrong!";
    std::cout << '\n';
    return 0;
}