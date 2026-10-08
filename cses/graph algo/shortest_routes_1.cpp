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


// terbalik untuk penggunaan pq !! kalu priority kecil gunakan >
struct compare{
    bool operator()(pair<ll,ll> a,pair<ll,ll> b){
        return a.second > b.second;
    }
};

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    vector<ll> w(n + 1, -1);
    for(int i = 0; i < m; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,compare> pq;
    pq.push({1,0});
    w[1] = 0;
    while(!pq.empty()){
        pair<ll,ll> cur = pq.top();
        pq.pop();
        ll cur_node = cur.first;
        ll cur_weight = cur.second;
        if(cur_weight != w[cur_node]) continue;
        for(auto x : adj[cur_node]){
            if(w[x.first] == -1 || x.second + cur_weight < w[x.first]){
                w[x.first] = x.second + cur_weight;
                pq.push({x.first,w[x.first]});
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout << w[i] << " ";
}

int main() {
    solve();
}