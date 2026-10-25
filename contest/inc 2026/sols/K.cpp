#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll l = 0,r = -1;
    vector<pair<ll,ll>> table(n),groups(m);
    for(auto x : table){
        cin >> x.first >> x.second;
        r = max(r,x.second);
    }
    for(auto x : groups){
        cin >> x.first >> x.second;
    }
    while(l <= r){
        ll mid = l + (r - l) / 2;
    }
}