#include <bits/stdc++.h>
using namespace std;


#define ll long long
map<char,pair<ll,ll>> mp = {{'D',{1,0}},{'U',{-1,0}},{'L',{0,-1}},{'R',{0,1}}};

ll n,m;
void dfs(vector<vector<bool>> &vis,ll x,ll y,vector<string> &s){
    vis[x][y] = true;
    ll next_x = x + mp[s[x][y]].first;
    ll next_y = y + mp[s[x][y]].second;
    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m || vis[next_x][next_y]) return;

    dfs(vis,next_x,next_y,s);
}
int main(){
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<ll>> deg(n,vector<ll>(m,0));
    for(auto &x : s) cin >> x;
    ll dg = 0;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; ++y){
            char c = s[i][y];
            ll idx_x = i + mp[c].first;
            ll idx_y = y + mp[c].second;
            if(idx_x >= 0 && idx_x < n && idx_y >= 0 && idx_y < m){
                deg[idx_x][idx_y]++;
                dg = max(dg,deg[idx_x][idx_y]);
            }
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    ll ans = 0;
    for(int i = 0; i <= dg; ++i){
        for(int x = 0; x < n; ++x){
            for(int y = 0; y < m; ++y){
                if(!vis[x][y] && deg[x][y] == i){
                    ++ans;
                    dfs(vis,x,y,s);
                }
            }
        }
    }
    cout << ans;
}