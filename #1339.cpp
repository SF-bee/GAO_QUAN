#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    
    ll ans = 0;
    ll y = 1;
    
    while (y <= n / 2) {
        ll q = n / (y + 1);
        if (q == 0) break;
        
        ll max_y = n / q - 1;
        if (max_y > n / 2) max_y = n / 2;
        
        ans += q * (max_y - y + 1);
        y = max_y + 1;
    }
    
    cout << ans << endl;
    return 0;
}