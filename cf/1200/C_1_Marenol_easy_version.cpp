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
    for(int i = 0; i < n; ++i){
        if(a[i] == '1'){
            if(i & 1) ++a1;
            else ++a2;
        }
    }
    for(int i = 0; i < n; ++i){
        if(b[i] == '1'){
            if(i & 1) ++b1;
            else ++b2;
        }
    }
    if(a1 == b1 && a2 == b2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}