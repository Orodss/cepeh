#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll maxn = 600851475143;
    ll ans = -1;
    for(ll i = 2; i * i <= maxn; i++){
        if(maxn % i == 0){
            while(maxn % i == 0) maxn /= i;
            ans = max(ans,i);
        }
    }
    if(maxn > 1) ans = max(ans,maxn);
    cout << ans;
}