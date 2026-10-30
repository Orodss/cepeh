#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll ans = 1;
    for(int i = 2; i <= 20; ++i) ans = (ans * i) / gcd(ans, i) ;
    cout << ans;
}