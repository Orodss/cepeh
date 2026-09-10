#include <bits/stdc++.h>
using namespace std;

#define ll long long



struct node{
    ll mx, mn;
};


vector<ll> a;
vector<node> t;

void build(ll v,ll tl,ll tr){
    if(tl == tr){
        t[v].mx = max(a[tl],a[tl + 1]);
        t[v].mn = min(a[tl],a[tl + 1]);
        return;
    }
    ll tm = (tl + tr) / 2;
    build(2*v,tl,tm);
    build(2*v + 1,tm + 1, tr);

    t[v].mx = max(t[2*v].mx,t[2*v + 1].mx);
    t[v].mn = min(t[2*v].mn,t[2*v + 1].mn);
}

ll query(ll v,ll tl,ll tr,ll l,ll r,ll val){
    if(l > r || t[v].mn > val || t[v].mx < val) return -1;

    if(tl == tr) return tl;

    ll tm = (tr + tl) / 2;
    ll left = query(
        2*v,tl,tm,l,min(r,tm),val
    );
    if(left != -1) return left;

    return query(2*v + 1,tm + 1,tr,max(l,tm + 1),r,val);
}


int main(){
    int n;
    cin >> n;
    a.resize(n + 1);
    t.resize(4 * n + 1);
    for(int i = 0; i <= n; ++i) cin >> a[i];
    build(1,0,n - 1);
    ll q;
    cin >> q;
    ll start,freq;
    while(q--){
        cin >> start >> freq;
        if(start > n){
            cout << -1 << '\n';
            continue;
        }
        if(start == n){
            if(a[n] == freq) cout << fixed << setprecision(7) << (double)n << "\n";
            else cout << -1 << "\n";
            continue;
        }
        ll idx = query(1,0,n - 1,start,n - 1,freq);
        // cout << "idx : " << idx << "\n";
        if(idx == -1) cout << -1 << "\n";
        else{
            double ans = 0;
            double mx = (double) max(a[idx],a[idx + 1]);
            double mn = (double) min(a[idx],a[idx + 1]);
            if(mx == mn){
                cout << idx << "\n";
                continue;
            }
            double x = (double)(freq - a[idx]) / (a[idx + 1] - a[idx]);
            ans += abs(x) + idx;
            cout << fixed << setprecision(7) << ans << "\n";
        }
    }
}