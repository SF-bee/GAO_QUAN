#include <bits/stdc++.h>

const int MAX = 1e4 + 5;
int n;
int a[MAX][4],b[MAX][4];

int check(int x[4],int y[4]){
    int your_right = 0;
    int ans_right = 0;
    for(int i = 0;i < 4;i++){
        if(x[i] == 1) ans_right++;
        if(y[i] == 1){
            if(x[i] == 1)
                your_right++;
            else return 0;
        }
    }
    if(your_right == ans_right) return 6;
    else if(your_right == 0) return 0;
    else return 3;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 0;i < n;i++)
        std::cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    for(int i = 0;i < n;i++)
        std::cin >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3];

    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = 0;j < n;j++){
            sum += check(a[(i + j) % n],b[j]);
        }
        std::cout << sum << ' ';
    }
    return 0;
}