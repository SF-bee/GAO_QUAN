#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e6 + 5;

int k;
ll pi[MAX],cnt[MAX];
std::string s;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> k >> s;
    for(int j = 0,i = 1;i < k;i++){
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) pi[i] = ++j;
    }
    for(int i = 0;i < k;i++){
        if(pi[i] == 0) cnt[i] = 0;
        else if(pi[pi[i] - 1] == 0) cnt[i] = pi[i];
        else cnt[i] = cnt[pi[i] - 1];
    }
    ll sum = 0;
    for(int i = 0;i < k;i++)
        sum += (cnt[i] != 0 ? i - cnt[i] + 1: 0);
    std::cout << sum << '\n';
    return 0;
}