#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll l = 1, r = 1e9;
    ll ans = -1;
    ll sum = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        ll sum = 0;
        ll length = 0;
        for(int i = 0; i < n; i++){
            if(v[i] >= mid) ++sum;
            else --sum;
            length++;
            if(length == 3){
                if(sum > 0){
                    ++cnt;
                    length = 0;
                    sum = 0;
                }else{
                    if(v[i - 2] >= mid) --sum;
                    else ++sum; 
                    --length;
                }
            }
        }
        if(cnt >= k){
            l = mid + 1;
            ans = mid;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
}