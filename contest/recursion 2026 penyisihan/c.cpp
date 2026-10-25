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


void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> v(3,vector<ll>(m));
    for(int i = 0; i < 2; ++i){
        for(int y = 0; y < m; ++y){
            cin >> v[i][y];
        }
    }
    vector<ll> pattern;
    bool found = false;
    for(int i = 0; i < m; i++){
        vector<ll> q;
        for(int y = 0; y < m; ++y) if(y != i) q.push_back(v[0][y]);
        ll l = 0;
        for(int y= 0; y < m; ++y){
            if(l < q.size() && v[1][y] == q[l]){
                ++l;
            }
        }
        if(l == v.size()){
            pattern = q;
            found = true;
            break;
        }
    }
    if(found){
        ll ans;
        for(int i = 2; i < n; ++i){
            ll l = 0;
            for(int y = 0; y < m; ++y){
                if(l < pattern.size() && v[i][y] == pattern[l]){
                    ++l;
                }
            }
            if(l != pattern.size()) ans = i + 1;
        }
        cout << ans << "\n";
    }else{
        for(int i = 0; i < m; ++i) cin >> v[2][i];
        bool found = false;
        for(int i = 0; i < m; ++i){
            vector<ll> q;
            for(int y = 0; y < m; ++y){
                // // cout << v[1][y] << "\n";
                // cout << "TEST";
                if(i != y) q.push_back(v[1][y]);
            }
            ll l = 0;
            for(int y = 0 ; y < m; ++y){
                if(l < q.size() && q[l] == v[2][y]) ++l;
            }
            if(l == q.size()){
                found = true;
                break;
            }
        }
        for(int i = 3; i < n; ++i){
            for(int y = 0; y < m; ++y){
                ll a;
                cin >> a;
            }
        }
        // cout << "test";
        if(found) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}