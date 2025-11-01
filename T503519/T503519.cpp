// #include <bits/stdc++.h>
// const int MAX = 1e6 + 5;

// int n,h[MAX],dp[2][MAX]; //dp[j][i]表示通过人走/机器走到第i层时需要人工走的步数

// int main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);
    
//     std::cin >> n;
//     for(int i = 0;i < n;i++)
//         std::cin >> h[i];
//     for(int i = 1;i <= n;i++){
//         //选择人走上来
//         dp[0][i] = std::min(dp[0][i - 1],dp[1][i - 1]) + h[i - 1];
//         //选择机器上来
//         if(i >= 2) //防止访问负数下标
//             dp[1][i] = std::min(dp[0][i - 1],dp[0][i - 2]);
//         else
//             dp[i][1] = dp[0][i - 1];
//     }
//     std::cout << std::min(dp[0][n],dp[1][n]) << '\n';
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n;
long long a[maxn], f[maxn][2];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i][1]=min(f[i-1][0],f[i-1][1])+a[i-1];
		f[i][0]=min(f[i-1][1],f[i-2][1]);
        f[-1][1];
	}
	cout<<min(f[n][1],f[n][0])<<endl;
    return 0;
}
/*
h  5 2 4 5 3 2
0
1
*/