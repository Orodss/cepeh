#include <bits/stdc++.h>

using namespace std;
#define ll long long
void dfs(map<ll,ll> &vis,ll x, ll parent,ll target){
    vis[x] = vis[parent] + 1;
    ll nxt = x / 2;
    if(nxt >= target)
        if(vis[nxt] == 0 || (vis[nxt] > vis[x] + 1)) dfs(vis,nxt,x,target);
    nxt = (x + 1) / 2;
    if(nxt >= target)
        if(vis[nxt] == 0 || (vis[nxt] > vis[x] + 1)) dfs(vis,nxt,x,target);
}
void solve(){
    ll x,k;
    cin >> x >> k;
    map<ll,ll> vis;
    vis[0] = 0;
    dfs(vis,x,0,k);
    if(vis[k] == 0 && k != x) vis[k] = -1;
    if(vis[k] != -1) vis[k]--;
    cout << vis[k] << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}