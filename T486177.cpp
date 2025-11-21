// #include <bits/stdc++.h>
// typedef long long lint;

// const int MAX = 5e2 + 5;
// int n,m,k,ans;
// std::array<int,MAX> arr[MAX];
// std::array<int,MAX> brr;

// int main(){
//     std::ios::sync_with_stdio(0);
//     std::cin.tie(0);

//     std::cin >> n >> m >> k;
//     for(int i = 1;i <= m;i++){
//         int x,y;
//         std::cin >> x >> y;
//         arr[x][y] = 1;
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
//         }
//     }

//     for(int i = 1;i <= n;i++){
//         for(int j = i;j <= n;j++){
//             for(int k = 1;k <= n;k++){
//                 brr[k] = arr[j][k] - arr[i - 1][k] - arr[j][k - 1] + arr[i - 1][k - 1];
//             }
//             for(int l = 1,r = 1,cnt = 0;r <= n;r++){
//                 cnt += brr[r];
//                 if(cnt >= k) {
//                     while(cnt >= k){
//                         ans += n - r + 1;
//                         cnt -= brr[l];
//                         l++;
                        
//                     }
//                 }
//             }
//         }
//     }
//     std::cout << ans;
//     return 0;
// }
#include<bits/stdc++.h> //
using namespace std;
typedef long long LL;
const int MAX=5e2+5;// 尺取法  + 二分 
int n,l,r,k,m;
LL a[MAX][MAX];
LL f[MAX][MAX], ans;

int  er(int up,int down){
	int x=n;
	while(up<=down){
		int mid=(up+down)/2 ;
		if(f[mid][r]-f[mid][l-1]-f[up-1][r]+f[up-1][l-1]>=k)
			x=min(x,mid),down=mid-1;
		else up=mid+1;
	}
	return x;	
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int x,y;	
		cin>>x>>y;
		a[x][y]=1;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
			
	for(l=1;l<=n;l++){
        for(r=1;r<=n;r++){
            int up = 1;
            while(up<=n)ans+=n-er(up,n)+1,	up++;
        }
    }
		
	cout<<ans;
	return 0;

}