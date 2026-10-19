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
    ll n,m,mod;
    cin >> n >> m >> mod;
    vector<vector<ll>> v(n,vector<ll>(m));
    for(auto &x : v){
        for(auto &y : x) cin >> y;
    }
    vector<vector<ll>> row(n,vector<ll>(m));
    for(int i = 0; i < n; i++){
        vector<ll> pref(m + 1,1),suf(m + 1,1);

        for(int y = 0; y < m; ++y){
            pref[y + 1] = pref[y] * v[i][y] % mod;
        }

        for(int y = m - 1; y >= 0; --y){
            suf[y] = suf[y + 1] * v[i][y] % mod;
        }
        for(int y = 0; y < m; ++y){
            row[i][y] = pref[y] * suf[y + 1] % mod; 
        }
    }

    vector<vector<ll>> prefix(n + 1,vector<ll>(m + 1,1)),suffix(n + 1,vector<ll>(m + 1, 1));
    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; ++y){
            prefix[i + 1][y] = prefix[i][y] * row[i][y] % mod;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int y = 0; y < m; ++y){
            suffix[i][y] = suffix[i + 1][y] * row[i][y] % mod;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int y = 0; y < m; ++y){
            suffix[i][y] = suffix[i + 1][y] * row[i][y] % mod;
        }
    }
    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; ++y){
            cout << prefix[i][y] * suffix[i + 1][y] % mod << " ";
        }
        cout << "\n";
    }
}

int main() {
    gg;
    int t = 1;
    while(t--) solve();
}