#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll odd = 0,even_2 = 0,even_0 = 0,odd_2 = 0,odd_0 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] & 1){
            ++odd;
        }else{
            ll num = v[i] / 2;
            if(num & 1){
                odd_0++;
                even_2++;
            }else{
                odd_2++;
                even_0++;
            }
        }
    }
    ll ans = -1;
    ans = max(ans,odd);
    ans = max(ans,odd_0);
    ans = max(ans,even_0);
    ans = max(ans,odd_2);
    ans = max(ans,even_0);
    cout << ans << "\n";
}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}