#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,a[MAX];
int lm[MAX],rm[MAX],sk[MAX];
int ans[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    int top = 0,i = 1;
    for(top = 0,i = 1;i <= n;i++){
        while(top > 0 && a[sk[top]] > a[i]){
            rm[sk[top]] = i - 1;
            top--;
        }
        sk[++top] = i;
    }
    while(top)
        rm[sk[top--]] = n;
    for(top = 0,i = n;i >= 1;i--){
        while(top > 0 && a[sk[top]] > a[i]){
            lm[sk[top]] = i + 1;
            top--;
        }
        sk[++top] = i;
    }
    while(top)
        lm[sk[top--]] = 1;
    for(i = 1;i <= n;i++)
        ans[rm[i] - lm[i] + 1] = std::max(ans[rm[i] - lm[i] + 1],a[i]);
    for(i = 1;i <= n;i++)
        std::cout << ans[i] << " \n"[i == n];
    for(i = n - 1;i >= 1;i--)
        ans[i] = std::max(ans[i],ans[i + 1]);
    for(i = 1;i <= n;i++)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}