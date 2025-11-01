#include <bits/stdc++.h>
const int MAX = 1e2;

int n,maxa,sum;
int l[MAX];

//lg表示需要拼的长度
//d表示当前拼到第几根木棍
//ng表示现在还差的长度
//last表示上一根木棍的长度
bool dfs(int lg,int d,int ng,int last){
    if(d == n) return true;
    for(int i = std::min(ng,last);i >= 1;i--) if(l[i]){
        l[i]--;
        bool flag = false;
        if(i == ng){ //这根刚好可以拼好，新开一根
            flag = dfs(lg,d + 1,lg,maxa);
            l[i]++;
            return flag;
        }
        else if(ng == lg){ //这根必须被拼掉
            flag = dfs(lg,d + 1,ng - i,i);
            l[i]++;
            return flag;
        }
        else{
            flag = dfs(lg,d + 1,ng - i,i);
            l[i]++;
            if(flag) return flag;
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int a,i = 1;i <= n;i++)
        std::cin >> a,l[a]++,sum += a,maxa = std::max(maxa,a);
    for(int i = maxa;i <= sum;i++){
        if(sum % i == 0 && dfs(i,0,i,maxa)){
            std::cout << i << '\n';
            break;
        }
    }
    return 0;
}