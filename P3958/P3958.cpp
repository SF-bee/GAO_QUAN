#include <bits/stdc++.h>

int T;
int n,h,r;

struct cheese
{
    int x,y,z;
};

double getdis(cheese a,cheese b)
{
    int px = (a.x - b.x) * (a.x - b.x);
    int py = (a.y - b.y) * (a.y - b.y);
    int pz = (a.z - b.z) * (a.z - b.z);
    return sqrt(px + py + pz);
}


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--)
    {
        std::cin >> n >> h >> r;
        std::vector<cheese> a(n);
        std::vector<bool> vis(n);
        std::queue<cheese> q;

        for(int i = 0;i < n;i++){
            std::cin >> a[i].x >> a[i].y >> a[i].z;
            if(a[i].z <= r){
                q.push(a[i]);
                vis[i] = 1;
            }
        }
        
        bool flag = 0;
        while(!q.empty())
        {
            auto [x,y,z] = q.front();q.pop();
            if(z + r >= h){flag = 1;break;}
            for(int i = 0;i < n;i++)
            {
                if(vis[i] != 1 && getdis({x,y,z},a[i]) <= 2 * r)
                {
                    q.push(a[i]);
                    vis[i] = 1;
                }
            }
        }
        if(flag) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}