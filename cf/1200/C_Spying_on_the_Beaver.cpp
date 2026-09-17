#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n + 1,0);
    for(int i = 2; i <= n; ++i){
        ll p; cin >> p;
        v[i] = v[p] + 1;
    }
    vector<pair<ll,ll>> q;
    ll m; cin >> m;
    for(int i = 0; i < m; ++i){
        ll node; cin >> node;
        q.push_back({v[node],node});
    }
    sort(q.rbegin(),q.rend());
    cout << m - 1 << " ";
    for(int i = 0; i < m - 1; ++i){
        cout << q[i].second << " ";
    }
    cout << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}