#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll,ll> m;
    for(auto &x : v){
        cin >> x;
        if(x == 0) m[x]++;
    }
    if(m[0] == 1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 0){
                if(cnt == 0){
                    cout << "C"; ++cnt;
                }else{
                    cout << "B";
                }
            }else{
                cout << "A";
            }
        }
        cout << "\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}