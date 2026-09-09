#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x :v) cin >> x;
    ll idx = 1;
    ll ans = 0;
    while(idx < n){
        if(v[idx] == v[idx - 1] || v[idx - 1] == 7 - v[idx]){
            ++ans;
            idx+=2;
        }else{
            idx++;
        }
    }
    cout << ans << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}