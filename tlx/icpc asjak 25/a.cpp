#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll gcds;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        if (i == 0){
            gcds = v[i];
        }else{
            gcds = gcd(gcds, v[i]);
        }
    }
    if (gcds == 1){
        cout << 2 << "\n";
        cout << 4 << " 2\n";
        cout << 4 << " 2";
    }else{
        cout << 1 << "\n";
        cout << gcds << " " << 1;
    }
}