#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int a;
    int cnt = 0;
    bool flag = 0;
    while(cin >> a){
        for(int i = 0;i < a;i++) {
            cout << flag;
            cnt ++;
            if(cnt == n) {
                cout << '\n';
                cnt = 0;
            }
        }
        flag = !flag;
    }
    return 0;
}