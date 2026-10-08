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


void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> w1(n + 1,vector<ll>(2,INF)); // idx 2 jumlah discount dipakai [0 or 1]
    using state = tuple<ll,ll,ll>;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(int i = 0; i < m; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    priority_queue<state,vector<state>,greater<state>>pq; // distance, discount, node
    w1[1][0] = 0;
    w1[1][1] = 0;
    pq.push({0,0,1});
    while(!pq.empty()){
        auto [a,b,c] = pq.top();
        pq.pop();

        if(w1[c][b] != a) continue;
        for(auto x : adj[c]){
            ll nw;
            // gk pakai discount
            nw = w1[c][b] + x.second;
            if(nw < w1[x.first][b]){
                w1[x.first][b] = nw;
                pq.push({nw,b,x.first});
            }

            if(!b){
                nw = w1[c][b] + (x.second / 2);
                if(nw < w1[x.first][1]){
                    w1[x.first][1] = nw;
                    pq.push({nw,1,x.first});
                }
            }
        }
    }
    cout << min(w1[n][1],w1[n][0]);
}

int main() {
    gg;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}