#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll maxn = 1e9;
vector<ll> st(maxn*4 + 1);

void build(vector<ll> &a,ll v,ll tl,ll tr){
    if(tl == tr){
        st[v] = a[tl];
    }else{
        ll tm = (tr + tl) / 2;
        build(a,v * 2,tl, tm);
        build(a,v * 2 + 1,tm + 1, tr);
        st[v] = st[v * 2] + st[v * 2 + 1];
    }
}

ll sum(ll v,ll tl,ll tr,ll l,ll r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return st[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(2 * v,tl,tm,l,min(tm,r)) + sum(2 * v + 1,tm + 1,tr,max(l,tm + 1),r);
}

void update(ll v,ll tl,ll tr,ll pos,ll val){
    if(tl == tr){
        st[v] = val;
        return;
    }
    ll tm = (tl + tr) / 2;
    if(pos <= tm)
        update(2 * v,tl,tm,pos,val);
    else
        update(2 * v + 1,tm + 1,tr,pos,val);
    st[v] = st[v*2] + st[v*2 + 1];
}
int main(){

}