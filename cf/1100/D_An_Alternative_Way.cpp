#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n),q(n);
    for(auto &x : v) cin >> x;
    for(ll &x : q) cin >> x;
    ll suma = 0,sumb = 0;
    for(int i = 0; i < n; i++){
        suma += v[i];
        sumb += q[i];
        if(suma > sumb){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}