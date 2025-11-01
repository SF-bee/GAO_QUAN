#include <bits/stdc++.h>

struct node{
    int f,p;
    bool operator < (const node &rhs) const{
        if(p != rhs.p) return p < rhs.p;
        else return f < rhs.f;
    }
};

int T;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){ 
        int n,m,r,s;
        std::cin >> n >> m >> r >> s;
        std::vector<node> a(n),b(n);
        for(int i = 0;i < n;i++)
            std::cin >> a[i].f;
        for(int i = 0;i < n;i++)
            std::cin >> a[i].p;
        for(int i = 0;i < n;i++)
            std::cin >> b[i].f;
        for(int i = 0;i < n;i++)
            std::cin >> b[i].p;
        std::sort(a.begin(),a.end());
        std::sort(b.begin(),b.end());
        node now;
        while(!a.empty() && !b.empty()){
            if(s == 1) {
                now = *a.begin();
                s = 2;
                a.erase(a.begin());
            }
            else if(s == 2){
                now = *b.begin();
                s = 1;
                b.erase(b.begin());
            }
            while(!a.empty() && !b.empty()){
                bool flag = false;
                if(s == 1){
                    for(auto i = a.begin();i != a.end();i++){
                        if((*i).f == now.f && (*i).p > now.p){
                            now = *i;
                            s = 2;
                            a.erase(i);
                            flag = true;
                            break;
                        }
                    }
                }
                else if(s == 2){
                    for(auto i = b.begin();i != b.end();i++){
                        if((*i).f == now.f && (*i).p > now.p){
                            now = *i;
                            s = 1;
                            b.erase(i);
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag){
                    s = (s == 1 ? 2 : 1);
                    break;
                }
            }
        }
        if(a.empty()) std::cout << "FS wins!\n";
        else std::cout << "FR wins!\n";
    }
    return 0;
}