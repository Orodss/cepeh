#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll x,y;
    cin >> x >> y;
    ll dif = abs(x - y);
    ll ans = 0;
    for(ll i = 2; i <= dif; ++i){
        if(dif % i == 0){
            ++ans;
        }
    }

    cout << ans + 1 << "\n";
    for(int i = 0; i < x; ++i) cout << 1 << " ";
    for(int i = 0; i < y;  ++i) cout << -1 << " ";
    cout << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}