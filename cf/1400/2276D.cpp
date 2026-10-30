#include <bits/stdc++.h>
using namespace std;

#define gg ios::sync_with_stdio(false); cin.tie(nullptr);

// output pair with cout 
// usage example cout << p; with p as a pair
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// print container 
template<typename T_container,
         typename T = typename enable_if<
             !is_same<T_container, string>::value,
             typename T_container::value_type
         >::type>
ostream& operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// debug printing 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

// debug macro, enable the local to use
//#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// dtypes
#define ll long long
#define ld long double

// vectors
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vl>
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define fr first
#define sc second

// maps
#define ml map<ll,ll>
#define mc map<char,ll>

// sort
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(x.rbegin(),x.rend());

// edges
const ll INF = LLONG_MAX;
const ll NINF = LLONG_MIN;

// output
#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

void dfs(ll cur,vector<bool> &vis, vector<vector<ll>> &adj,ll &sz){
    for(auto x : adj[cur]){
        if(!vis[x]){
            ++sz;
            vis[x] = true;
            dfs(x,vis,adj,sz);
        }
    }
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    vector<ll> deg(n + 1);
    ll sumn = 0, suma = 0;
    for(int i = 0; i < m; ++i){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ll sz = 1;
            vis[i] = true;
            dfs(i,vis,adj,sz);
            if(sz == 1){
                cout << "Brain Melt\n";
                return;
            }
            ++cnt;
        }
    }
    if(cnt > 1){
            cout << "Many\n";
            return;
        }
    for(int i = 1; i <= n; ++i){
        if(deg[i] == 1) suma++;
        else if(deg[i] == n - 1) sumn++;
    }
    if(sumn == 1 && suma == n  - 1) cout << 2 << "\n";
    else cout << "Many\n";
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}