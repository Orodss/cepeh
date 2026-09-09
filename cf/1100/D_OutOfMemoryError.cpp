#include <bits/stdc++.h>

using namespace std;
#define ll long long
void solve(){
    ll n,m,h;
    cin >> n >> m >> h;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    vector<ll> q(n);
    for(int i = 0; i < n; ++i){
        q[i] = v[i];
    }
    ll lts = -1;
    map<ll,ll> mp;
    for(int i = 0; i < m; ++i){
        ll a,b;
        cin >> a >> b;
        if(lts > mp[a]){
            q[a - 1] = v[a - 1];
        }
        q[a - 1] += b;
        if(q[a - 1] > h){
            lts = i;
            q[a - 1] = v[a - 1];
        }
        mp[a] = i;
    }
    for(int i = 0; i < n; ++i){
        if(mp[i + 1] < lts) q[i] = v[i];
    }
    for(auto x : q) cout << x << " ";
    cout << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}