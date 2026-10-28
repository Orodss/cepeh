#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU{
    vector<ll> p,lvl;
    ll components;
    DSU(ll n){
        p.resize(n + 1);
        lvl.assign(n + 1, 0);
        iota(p.begin(),p.end(), 0);
        components = n;
    }

    ll find(ll x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool merge(ll a,ll b){
        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(a < b) swap(a,b);
        p[b] = a;

        if(lvl[a] == lvl[b]) lvl[a]++;
        --components;
        return true;
    }
};

int main(){

}