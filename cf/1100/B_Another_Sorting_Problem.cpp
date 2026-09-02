#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 1; i < n - 1; ++i){
        if(v[i] < v[i - 1] && v[i] > v[i + 1]){
            cout << "NO\n";
            return;
        }
    }
    ll k = -1;
    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            k = max(k,v[i] - v[i + 1]);
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(v[i] > v[i + 1]){
            v[i + 1] += k;
        }
    }
    for(int i = 1; i < n; ++i){
        if(v[i] < v[i - 1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int tc;
    cin >> tc; while(tc--)solve();
}