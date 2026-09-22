#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> bit;
void update(ll idx,ll val){
    for(; idx <= bit.size(); idx += idx & -idx){
        bit[idx] += val;
    }
}

ll query(ll idx){
    ll res = 0;
    for(; idx > 0; idx -= idx & -idx){
        res += bit[idx];
    }
    return res;
}

int main(){
    int n; cin >> n;
    bit.resize(n + 2);
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    bit[0] = 0;
    ll q;
    cin >> q;
    while(q--){
        ll cmd;
        cin >> cmd;
        if(cmd == 1){
            ll l,v,r;
            cin >> l >> v >> r;
            update(l,r);
            update(v + 1,-r);
        }else{
            ll idx;
            cin >> idx;
            cout << v[idx - 1] + query(idx) << "\n";
        }
    }
}