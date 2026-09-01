#include <bits/stdc++.h>

using namespace std;

#define ll long long
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.rbegin(),v.rend());
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > m) ++cnt;
        else break;
    }
    ll i = 0;
    ll ans = 0;
    // cout << ((n + 1) / 2) << " " << cnt << "\n";
    for(int i = 0; i < max(cnt,(n + 1) / 2); ++i){
        ans += v[i] - m;
        // cout << v[i] - m << " ";
    }
    // cout << "\n";
    cout << ans << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}