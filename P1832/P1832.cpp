#include <bits/stdc++.h>

const int MAX = 1005;
int n;
bool s[MAX];
long long dp[MAX];

void Eratosthenes() {
    s[0] = s[1] = false;
    for (int i = 2; i <= MAX; ++i) s[i] = true;
    for (int i = 2; i <= MAX; ++i) {
        if (s[i]) {
            if ((long long)i * i > MAX) continue;
            for (int j = i * i; j <= MAX; j += i)
                s[j] = false;  
        }
    }
}

int main(){
    std::cin >> n;
    Eratosthenes();
    dp[0] = 1;
    for(int i = 2;i <= n;i++){
        if(s[i]){
            for(int j = i;j <= n;j++){
                dp[j] += dp[j - i];
            }
        }
        
    }
    std::cout << dp[n];
    return 0;
}