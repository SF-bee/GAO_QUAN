#include <bits/stdc++.h>
#define int long long
const int MAX = 1e5;
const int N = 1e3 + 5;

// struct Big{ 
//     int len,num[MAX];
//     Big(int x = 0){
//         *this = x;
//     }
//     Big& operator = (int x){
//         len = 0;
//         std::memset(num, 0, sizeof(num));
//         if (x == 0){
//             len = 1;
//             num[1] = 0;
//             return *this;
//         }
//         while (x){
//             num[++len] = x % 10;
//             x /= 10;
//         }
//         return *this;
//     }
//     bool operator < (const Big &rhs) const{
//         if(len != rhs.len) return len < rhs.len;
//         else{
//             for(int i = len;i >= 1;i--)
//                 if(num[i] != rhs.num[i]) return num[i] < rhs.num[i];
//             return 1;
//         }
//     }
//     Big operator + (const Big &rhs) const{
//         Big c;
//         c.len = std::max(len,rhs.len);
//         std::memset(c.num,0,sizeof(c.num));
//         for(int i = 1;i <= c.len;i++){
//             c.num[i] += num[i] + rhs.num[i];
//             c.num[i + 1] += c.num[i] / 10,c.num[i] %= 10;
//         }
//         while(c.num[c.len + 1]){
//             c.len++;
//             c.num[c.len + 1] += c.num[c.len] / 10,c.num[c.len] %= 10;
//         }
//         return c;
//     }
//     Big operator - (const Big &rhs) const{
//         Big c;
//         c.len = len;
//         std::memset(c.num,0,sizeof(c.num));
//         for(int i = 1;i <= c.len;i++){
//             c.num[i] += num[i] - rhs.num[i];
//             if (c.num[i] < 0) {
//                 c.num[i + 1] -= 1;
//                 c.num[i] += 10;
//             }
//         }
//         while(c.len > 1 && c.num[c.len] == 0) c.len--;
//         return c;
//     }
//     Big operator * (const Big &rhs) const{
//         Big c;
//         c.len = std::max(len,rhs.len);
//         std::memset(c.num,0,sizeof(c.num));
//         for(int i = 1;i <= c.len;i++)
//             for (int j = 1; j <= (c.len == len ? rhs.len : len); ++j)
//                 c.num[i + j - 1] += num[i] * rhs.num[j];
//         for(int i = 1;i <= c.len;i++)
//             c.num[i + 1] += c.num[i] / 10,c.num[i] %= 10;
//         while(c.num[c.len + 1]){
//             c.len++;
//             c.num[c.len + 1] += c.num[c.len] / 10,c.num[c.len] %= 10;
//         }
//         return c;
//     }
//     Big operator / (const int &rhs) const {
//         if (*this < rhs) {
//             return Big(0);
//         }
//         Big c;
//         c.len = len;
//         int d = 0;
//         std::memset(c.num, 0, sizeof(c.num));
//         for(int i = c.len;i >= 1;i--){
//             c.num[i] = (d * 10 + num[i]) / rhs;
//             d = (d * 10 + num[i]) % rhs;
//         }
//         while(!c.num[c.len]) c.len--;
//         return c;
//     }
    // friend std::ostream& operator<<(std::ostream &os, const Big &rhs){
    //     for(int i = rhs.len;i >= 1;i--)
    //         os << rhs.num[i];
    //     return os;
    // }
// };
class hp{
    public:
    int a[MAX];
    hp(){memset(a,0,sizeof(a));}
    void clear(){memset(a,0,sizeof(a));}
    hp(int x){
        clear();
        while(x){
            a[++a[0]]=x%10;
            x/=10;
        }
        while(a[a[0]]==0&&a[0])a[0]--;
    }
    hp& operator=(int x){
        clear();
        while(x){
            a[++a[0]]=x%10;
            x/=10;
        }
        while(a[a[0]]==0&&a[0])a[0]--;
        return *this;
    }

    short cmp(const hp& x){
        if(a[0]>x.a[0])return 1;
        if(a[0]<x.a[0])return -1;
        for(register int i=a[0];i>=1;i--){
            if(a[i]>x.a[i])return 1;
            if(a[i]<x.a[i])return -1;
        }
        return 0;
    }
    bool operator>(const hp& x){
        return cmp(x)==1;
    }
    bool operator==(const hp& x){
        return cmp(x)==0;
    }
    bool operator<(const hp& x){
        return cmp(x)==-1;
    }
    bool operator>=(const hp& x){
        return !(*this<x);
    }
    bool operator<=(const hp& x){
        return !(*this>x);
    }
    
    hp operator-(const hp& x){
        hp a=*this,c;
        c.a[0]=a.a[0]>x.a[0]?a.a[0]:x.a[0];
        for(register int i=1;i<=c.a[0];i++) {
            c.a[i]+=a.a[i]-x.a[i];
            if(c.a[i]<0){c.a[i]+=10;a.a[i+1]--;}
        }
        while(c.a[c.a[0]]==0&&c.a[0])c.a[0]--;
        return c;
    }
    hp operator*(const hp& x){
        hp c;
        for(register int i=1;i<=a[0];i++){
            for(register int j=1;j<=x.a[0];j++){ 
                c.a[i+j-1]+=a[i]*x.a[j];
            }
        }
        c.a[0]=a[0]+x.a[0];
        for(register int i=1;i<=c.a[0];i++){
            if(c.a[i]>=10){
                c.a[i+1]+=c.a[i]/10;
                c.a[i]%=10;
            }
        }
        while (c.a[c.a[0]]==0&&c.a[0]>0)c.a[0]--;
        return c;
    }
    hp operator/(const int& x){
        hp c;
        int t=0,s=0;
        bool flag=1;
        for(register int i=a[0];i>=1;i--){
            t=s*10+a[i];
            if(t/x>0||t==0){
                c.a[++c.a[0]]=t/x;
                s=t%x;
                flag=0;
            }
            else{
                s=t;
                if(!flag)c.a[++c.a[0]]=0;
            }
        }
        std::reverse(c.a+1,c.a+c.a[0]+1);
        return c;
    }
    friend std::ostream& operator<<(std::ostream &os, const hp &rhs){
        for(int i = rhs.a[0];i >= 1;i--)
            os << rhs.a[i];
        return os;
    }
};
void checkmax(hp& x,hp y){
    if(x < y) x = y;
}
struct node{
    int a,b;
    bool operator < (const node &rhs){
        return a * b < rhs.a * rhs.b;
    }

}man[N];
int n;
hp maxa = 0;

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n + 1;i++)
        std::cin >> man[i].a >> man[i].b;
    std::sort(man + 2,man + n + 1);
    hp sum = man[1].a;
    for(int i = 2;i <= n + 1;i++){
        checkmax(maxa,hp(sum / man[i].b));
        sum = sum * man[i].a;
    }
    std::cout << maxa << '\n';
    return 0;
}