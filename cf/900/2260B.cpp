#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ll x,y,k;
        cin >> x >> y >> k;
        if(x > y){

        }
        ll p = 0;
        ll ans = 0;
        while(p < k){
            ans += y % x;
            ++y;
            ++x;
            ++p;
            if(y % x == (y - x)) break;
        }
        ans += (y - x) * (k - p);
        cout << ans << "\n";
    }
}