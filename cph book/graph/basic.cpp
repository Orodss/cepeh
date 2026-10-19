#include <bits/stdc++.h>
using namespace std;
#define ll long long


// find out whether a graph can be colored using only 2 colors where a node needs to have a different color with it's neighbour
bool dfs_bipartite(ll cur,ll clr,vector<vector<ll>> &adj,vector<ll> &color){
    color[cur] = clr;


    for(auto x : adj[cur]){
        if(color[x] == -1){
            if(!dfs_bipartite(x, 1 - clr, adj, color)) return false;
        }else{
            if(color[x] == clr) return false;
        }
    }
    return true;
}

int main(){

    vector<vector<ll>> adj(7);
    // bipartite
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[4].push_back(1);
    adj[5].push_back(1);
    adj[5].push_back(2);
    adj[5].push_back(6);
    adj[2].push_back(5);
    adj[2].push_back(3);
    adj[6].push_back(3);
    adj[6].push_back(5);
    // non bipartite
    // adj[4].push_back(5);
    // adj[5].push_back(4);
    
    vector<ll> color(7, -1);
    ll bip = true;
    for(int i = 1;  i <= 6; ++i){
        if(color[i] == -1){
            bip = dfs_bipartite(i,0,adj,color);
        }
    }
    if(bip) cout << "the graph is bipartite  !!";
    else cout << "the graph is not bipartite  !!";
}