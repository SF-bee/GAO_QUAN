#include<iostream>
#include<algorithm>

struct node{
    int a,b,c,sumabc,sumab,mxab,id;
}a[10005];

int n,S[10005];

bool check(node a,node b){
    if(a.sumabc==b.sumabc)
        if(a.sumab==b.sumab)
            if(a.mxab==b.mxab)
                return true;
    return false;
}

bool cmp(node a,node b){
    if(a.sumabc!=b.sumabc) return a.sumabc>b.sumabc;
    else if(a.sumab!=b.sumab) return a.sumab>b.sumab;
    else if(a.mxab!=b.mxab) return a.mxab>b.mxab;
    return false;
}

int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].sumabc=a[i].a+a[i].b+a[i].c;
        a[i].sumab=a[i].a+a[i].b;
        a[i].mxab=std::max(a[i].a,a[i].b);
        a[i].id=i;
    }
    
    std::sort(a+1,a+1+n,cmp);
    
    for(int i=1;i<=n;i++){
        S[a[i].id]=i;
        if(check(a[i],a[i-1]))
            S[a[i].id]=i-1;
    }
    
    for(int i=1;i<=n;i++){
        std::cout<<S[i]<<std::endl;
    }
}