#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll a){
    string as= to_string(a);
    ll l = 0, r = as.size() - 1;
    while(l < r){
        if(as[l] != as[r]) return false;
        ++l;
        r--;
    }
    return true;
}

int main(){
    ll ans = -1;
    for(ll i = 100; i <= 999; ++i){
        for(ll y = 100; y <= 999; ++y){
            if(check(i * y)) ans = max(ans,i * y); 
        }
    }
    cout << ans;
}