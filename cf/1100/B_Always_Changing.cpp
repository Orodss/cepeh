#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    string s;
    cin >> n >> s;
    ll a = 0, b = 0;
    ll a_sum = 0, b_sum = 0;
    if(s[0] == '1'){
        ++a;
        ++a_sum;
    }
    else{
        ++b;
        ++b_sum;
    }
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1]){
            if(s[i] == '1') ++a;
            else ++b;
        }
        if(s[i] == '1') ++a_sum;
        else ++b_sum;
    }
    ll delta_n = a_sum - b_sum;
    ll delta_l = a - b;
    if(abs(delta_n) > 2){
        cout << -1 << "\n";
    }else{
        ll ans = (n - (a + b));
        if(abs(delta_n - delta_l) > 1) ans += abs(delta_n - delta_l) - 1;
        cout << ans << "\n";
    }
}

int main(){
    ll tc;
    cin >> tc;
    while(tc--) solve();
}