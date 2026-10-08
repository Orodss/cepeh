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
const ll INF = 1e18;
const ll NINF = LLONG_MIN;

// output
#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

struct e{
    ll u,v,w;
};

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> w(n + 1, INF);
    vector<e> ev(m);
    vector<vector<ll>> v(n + 1);
    vector<ll> reach(n + 1, false);
    reach[n] = true;
    for(auto &x : ev){
        cin >> x.u >> x.v >> x.w;
        x.w = -1 * x.w;
        v[x.v].pb(x.u);
    }
    queue<ll> q;
    q.push(n);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll x : v[cur]){
            if(reach[cur] && !reach[x]){
                reach[x] = true;
                q.push(x);
            }
        }
    }
    ll source = 1;
    w[source] = 0;
    for(int i = 1; i <= n - 1; ++i){
        bool changed = false;
        for (auto &[a,b,c] : ev){
            if(w[a] != INF && w[a] + c < w[b]){
                changed = true;
                w[b] = w[a] + c;
            }
        }
        if(!changed) break;
    }
    bool negative = false;
        for (auto &[a,b,c] : ev){
            if(w[a] != INF && w[a] + c < w[b] && reach[b]){
                negative = true;
                w[b] = w[a] + c;
            }
        }
    if(negative) cout << -1;
    else cout << -1LL * w[n];
}

int main() {
    gg;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}