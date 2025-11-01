#include <bits/stdc++.h>

unsigned int n,mask = 0xff,nx,ny;
int x,y;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> x >> y;
    int cx = x << 3,cy = y << 3;
    nx = (n >> cx) & mask;
    ny = (n >> cy) & mask;
    n &= (~(nx << cx));
    n &= (~(ny << cy));
    n |= ny << cx;
    n |= nx << cy;
    std::cout << n << '\n';
    return 0;
}