#include <bits/stdc++.h>
using namespace std;

#define ll long long


void build(vector<ll> &t,vector<ll> &q,ll v,ll tl,ll tr){
    if(tl == tr){
        t[v] = q[tl];
        return;
    }

    ll tm = (tr + tl) / 2;

    build(t,q,2*v,tl,tm);
    build(t,q,2*v + 1,tm + 1, tr);
    t[v] = max(t[2*v],t[2*v + 1]);
}

ll mx(vector<ll> &t,ll v,ll tl,ll tr,ll l,ll r){
    if(l > r){
        return LLONG_MIN;
    }

    if(tl == l && tr == r){
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    ll val1 = mx(t,2*v,tl,tm,l,min(r,tm));
    ll val2 = mx(t,2*v + 1,tm + 1,tr,max(l,tm + 1),r);
    return max(val1,val2);
}

void update(vector<ll> &t,ll v,ll tl,ll tr,ll pos,ll val){
    if(tl == tr){
        t[v] = val;
        return;
    }
    ll tm = (tr + tl) / 2;
    if(pos <= tm){
        update(t,2*v,tl,tm,pos,val);
    }else{
        update(t,2*v+1,tm+1,tr,pos,val);
    }
    t[v] = max(t[v*2],t[v*2 + 1]);
}
int main(){
    ll n;
    cin >> n;
    vector<ll> t(4 * n + 1,0);
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    build(t,v,1,0,n-1);
    ll q;
    cin >> q;
    while(q--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            --b;
            update(t,1,0,n-1,b,c);
        }else{
            --b; --c;
            cout << mx(t,1,0,n-1,b,c) << "\n";
        }
    }
}