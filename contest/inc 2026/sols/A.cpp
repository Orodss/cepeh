#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin >> n;
    ll mx = -1;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        mx = max(mx,a);
    }
    cout << mx;
}