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
#define LOCAL
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


void dfs(ll mx,ll cur,vector<vector<ll>> &adj,vector<ll> &w,ll clr,ll &cnt){
    for(auto x : adj[cur]){
        if(w[x] == 0){
            if(cnt + 1 <= mx){
                w[x] = clr;
                ++cnt;
                dfs(mx,x,adj,w,clr,cnt);
            }
        }
    }
}

void dfs2(ll cur,vector<vector<ll>> &adj,vector<ll> &deg){
    for(auto x : adj[cur]){
        deg[x] = deg[cur] + 1;
        dfs2(x,adj,deg);
    }
}
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    vector<ll> w(n + 1, 0);
    for(int i = 1;  i <= n; ++i){
        cin >> v[i];
        if(v[i] != 0) w[i] = i;
    }
    vector<ll> deg(n + 1,  0);
    deg[0] = -1;
    vector<vector<ll>> adj(n + 1);
    vector<pair<ll,ll>> p;
    for(int i = 1; i < n; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        p.push_back({a,b});
    }
    dfs2(1,adj,deg);
    vector<pair<ll,ll>> q;
    for(int i = 1; i <= n; ++i){
        q.push_back({deg[i],i});
    }
    sort(q.rbegin(),q.rend());
    for(int i = 0; i < n - 1; i++){
        adj[p[i].second].push_back(p[i].first);
    }

    for(int i = 0; i < n; i++){
        ll r = q[i].second;
        if(v[r] != 0){
            ll cnt = 1;
            w[r] = r;
            dfs(v[r],r,adj,w,r,cnt);
            if(cnt != v[r]){
                cout << "TIDAK\n";
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(w[i] == 0){
            cout << "TIDAK\n";
            return;
        }
    }
    cout << "YA\n";
    for(int i = 1; i <= n; ++i) cout << w[i] << " ";
    cout << "\n";
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}