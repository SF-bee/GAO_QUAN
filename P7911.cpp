#include <bits/stdc++.h>

int n,cnt;
std::regex re("((\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}((\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\:)((\\d|[1-9]\\d{1,3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5]))");
std::unordered_map<std::string,int> server;
std::set<std::string> client;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::string op, x;
        std::cin >> op >> x;
        if(std::regex_match(x,re)){
            if(op == "Server"){
                if(server.count(x) == 0) server[x] = i,std::cout << "OK\n";
                else std::cout << "FAIL\n";
            }
            else if(op == "Client"){
                if(server.count(x) == 1) std::cout << server[x] << '\n';
                else std::cout << "FAIL\n";
            }
        }
        else std::cout << "ERR\n";
    }
    return 0;
}