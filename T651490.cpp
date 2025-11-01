#include <bits/stdc++.h>
#define db(x) ((x) * (x))
const double INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e2 + 5;

struct point{
    double x, y;
}pS[MAX];

double get_len(point a,point b) {return std::sqrt(db(a.x - b.x) + db(a.y - b.y));}
double get_size(point a,point b,point c){
    double ab = get_len(a,b);
    double bc = get_len(b,c);
    double ac = get_len(a,c);
    double p = (ab + bc + ac) / 2;
    return std::sqrt(p * (p - ab) * (p - bc) * (p - ac));
}
double get_S(std::vector<double> vec){
    double res = 0,u = 0;
    for(auto i : vec)
        res += db(i),u += i;
    u /= vec.size();
    res /= vec.size();
    return res - db(u);
}
//dp[l][r]表示l~r区间的顶点剖分出各个三角形的最小的平方和
//sum[l][r]表示l~r区间多边形的面积
int n;
double sum,ans = INF,dp[MAX][MAX];

int main(){
    // #if !ONLINE_JUDGE
    // freopen("T3_bigsample.in","r",stdin);
    // #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> pS[i].x >> pS[i].y;
    if(n == 3){
        std::cout << 0 << '\n';
        return 0;
    }
    std::memset(dp, 0x3f, sizeof(dp));
    for(int i = 2;i <= n;i++)
        sum += get_size(pS[1],pS[i - 1],pS[i]);
    
    for(int len = 3;len < n;len++){
        for(int l = 1;l + len <= 2 * n;l++){
            int r = l + len;
            if(len == 3){
                dp[l][r] = db(get_size(pS[l],pS[l + 1],pS[r]));
            }
            else{
                for(int k = l + 1;k < r;k++){
                    double area = get_size(pS[l],pS[k],pS[r]);
                    dp[l][r] = std::min(dp[l][r],
                                        dp[l][k] + dp[k][r] + db(area));    
                }
            }
        }
    }
    for(int i = 1;i <= n;i++)
        ans = std::min(ans,dp[i][i + n - 1] / (n - 2) - db(sum / n));
    std::cout << ans << '\n';
    return 0;
}