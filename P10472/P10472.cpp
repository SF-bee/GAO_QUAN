#include <bits/stdc++.h>
typedef long long ll;

const int MAX = 1e6 + 5;
int n,ans;
bool vis[MAX];
std::string s;
std::stack<int> bracket;


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            bracket.push(i);
        else if(s[i] == ')'){
            if(!bracket.empty())
                if(s[bracket.top()] == '(') vis[i] = vis[bracket.top()] = 1,bracket.pop();
            else bracket.push(i);
        }
        else if(s[i] == ']'){
            if(!bracket.empty())
                if(s[bracket.top()] == '[') vis[i] = vis[bracket.top()] = 1,bracket.pop();
            else bracket.push(i);
        }
        else if(s[i] == '}'){
            if(!bracket.empty())
                if(s[bracket.top()] == '{') vis[i] = vis[bracket.top()] = 1,bracket.pop();
            else bracket.push(i);
        }
    }
    for(int i = 0;i < n;i++){
        int now = i;
        if(vis[i]){
            for(int &j = i;j < n;j++)
                if(!vis[i]) break;
            i -= 1;
            ans = std::max(ans,(i - now + 1));
        }
    }
    std::cout << ans;
    return 0;
}