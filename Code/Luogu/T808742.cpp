#include <bits/stdc++.h>
using ull = unsigned long long;

std::map<char, std::string> mp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    std::string str;
    std::cin >> n >> str;
    mp['0'] = "0000", mp['1'] = "0001", mp['2'] = "0010", mp['3'] = "0011";
    mp['4'] = "0100", mp['5'] = "0101", mp['6'] = "0110", mp['7'] = "0111";
    mp['8'] = "1000", mp['9'] = "1001", mp['A'] = "1010", mp['B'] = "1011";
    mp['C'] = "1100", mp['D'] = "1101", mp['E'] = "1110", mp['F'] = "1111";
    std::string ans = "";
    for (auto ch : str)
        ans += mp[ch];
    while (ans.front() == '0')
        ans.erase(ans.begin());
    std::cout << ans << '\n';
    return 0;
}