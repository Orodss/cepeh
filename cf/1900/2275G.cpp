#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU{
    vector<ll> p;
    DSU(ll n){
        p.resize(n);
        iota(p.begin(),p.end(), 0);
    }
    ll find(ll x){
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    ll merge(ll a,ll b){
        a = find(a);
        b = find(b);
        if(a == b) return false;

        p[b] = a;
        return true;
    }
};


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ll n,m,q;
        cin >> n >> m >> q;
        vector<array<ll,3>> adj;
        ll total = 0;
        for(int i = 0; i < m; ++i){
            ll u,v,d;
            cin >> u >> v >> d;
            adj.push_back({d,u - 1,v - 1});
            total += d;
        }
        sort(adj.begin(),adj.end());
        vector<ll> w;
        DSU dsu(n);
        for(auto x : adj){
            if(dsu.merge(x[1],x[2])) w.push_back(x[0]);
        }
        ll top = w.size();
        vector<ll> prefix(top + 1, 0);
        for(int i = 1; i <= top; ++i){
            prefix[i] = prefix[i - 1] + w[i - 1];
        }
        while(q--){
            ll x;
            cin >> x;
            ll l = 0, r = top;
            while(l < r){
                ll mid = l + (r - l) / 2;
                if(w[mid] >= x * (n - mid - 1)) r = mid;
                else l = mid + 1;
            }
            ll k = n - l - 1;
            ll sum = prefix[l] + x *(k * (k + 1) / 2);
            cout << total - sum << " ";
        }
        cout << "\n";
    }
}