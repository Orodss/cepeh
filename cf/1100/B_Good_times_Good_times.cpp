#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll a;
    cin >> a;
    ll ans = 1;
    while(a > 0){
        ans *= 10;
        a /= 10;
    }
    cout << ans + 1 << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}