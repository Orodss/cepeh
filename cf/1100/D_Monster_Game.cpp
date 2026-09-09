#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n; cin >> n;
    vector<ll> v(n), m(n);
    for(auto &x : v) cin >> x;
    for(int i = 0; i < n; ++i){
        cin >> m[i];
        if(i > 0) m[i] += m[i - 1];
    }
    sort(v.rbegin(),v.rend());
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll it = upper_bound(m.begin(),m.end(),i) - m.begin();
        ans = max(ans,it * v[i  -1]);
    }
    cout << ans << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}