#include<bits/stdc++.h>

double x,a,y,b;

int main(){
	std::cin >> x >> a >> y >>b;
    std::cout << std::fixed << std::setprecision(2) << (x * a - y * b) / (a - b) << '\n';
	return 0;
}