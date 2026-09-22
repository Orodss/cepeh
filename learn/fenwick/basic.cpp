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
    bit.resize(n + 1);
    bit[0] = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        update(i + 1,a);
    }
    ll q;
    cin >> q;
    while(q--){
        ll cmd,a,b; cin >> cmd >> a >> b;
        if(cmd == 1){
            update(a,b);
        }else{
            cout << query(b) - query(a - 1) << "\n";
        }
    }
}