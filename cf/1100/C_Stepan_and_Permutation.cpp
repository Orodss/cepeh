#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    int g = gcd(x,y);
    for(int i = 0; i < n; ++i){
        if((i+1) % g != v[i] % g){
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