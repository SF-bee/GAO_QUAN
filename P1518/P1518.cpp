#include <bits/stdc++.h>

struct node{
    int fx,fy,cx,cy,fd,cd;
    
    bool operator < (const node &r) const{
        if(fx != r.fx) return fx < r.fx;
        else if(fy != r.fy) return fy < r.fy;
        else if(cx != r.cx) return cx < r.cx;
        else if(cy != r.cy) return cy < r.cy;
        else if(fd != r.fd) return fd < r.fd;
        else return cd < r.cd;
    }
};

char m[20][20];
int fx,fy,cx,cy,fd,cd;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int tim;
std::set<node> s;

bool check(){
    return fx == cx && fy == cy;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for(int i = 0;i <= 11;i++){
        for(int j = 0;j <= 11;j++){
            if(i == 0 || j == 0 || i == 11 || j == 11){
                m[i][j] = '#';
            }
            else{
                std::cin >> m[i][j];
                if(m[i][j] == 'F'){
                    m[i][j] = '.';
                    fx = i;
                    fy = j;
                }
                else if(m[i][j] == 'C'){
                    m[i][j] = '.';
                    cx = i;
                    cy = j;
                }
            }
        }
    }
    s.insert({fx,fy,cx,cy,fd,cd});
    while(1){
        //Cow
        if(m[cx + dir[cd][0]][cy + dir[cd][1]] == '.'){
            cx += dir[cd][0];
            cy += dir[cd][1];
        }
        else cd = (cd + 1) % 4;
        //Farmer
        if(m[fx + dir[fd][0]][fy + dir[fd][1]] == '.'){
            fx += dir[fd][0];
            fy += dir[fd][1];
        }
        else fd = (fd + 1) % 4;
        //std::cout << fx << ' ' << fy <<' ' << cx << ' ' << cy << '\n';
        tim += 1;
        if(s.count({fx,fy,cx,cy,fd,cd}) == 1){
            std::cout << 0;
            return 0;
        }
        else if(check()){
            std::cout << tim;
            return 0;
        }
        s.insert({fx,fy,cx,cy,fd,cd});
    }
    return 0;
}