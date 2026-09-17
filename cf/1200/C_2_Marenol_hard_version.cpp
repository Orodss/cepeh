#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    ll a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    vector<ll> a_1,a_2,b_1,b_2;
    for(int i = 0; i < n; ++i){
        if(a[i] == '1'){
            if(i & 1) ++a1;
            else ++a2;

            if(i & 1) a_1.push_back(i);
            else a_2.push_back(i);
        }
    }
    for(int i = 0; i < n; ++i){
        if(b[i] == '1'){
            if(i & 1) ++b1;
            else ++b2;

            if(i & 1) b_1.push_back(i);
            else b_2.push_back(i);
        }
    }
    if(a1 != b1 || a2 != b2) cout << "-1\n";
    else{
        ll ans = 0;
        for(int i = 0; i < a_1.size(); ++i){
            ans += abs((b_1[i] - a_1[i]) /2);
        }
        for(int i = 0; i < a_2.size(); ++i){
            ans += abs((b_2[i] - a_2[i]) / 2);
        }
        cout << ans << "\n";
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}