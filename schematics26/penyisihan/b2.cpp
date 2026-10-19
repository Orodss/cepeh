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


vector<ll> check_longest(string s){
    ll n = s.size();
    vector<ll> dp(n);
    ll l = 0, r = -1;
    for(int i = 0; i < n; i++){
        ll k;
        if(i > r) k = 1;
        else k = min(dp[l + r - i],r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        dp[i] = k;
        if(i + k - 1 > r){
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    for(auto &x : dp) x = 2 * x - 1;
    return dp;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> v(n,vector<char>(m));
    for(auto &x : v){
        for(auto &y : x){
            cin >> y;
        }
    }
    vector<vector<ll>> row(n,vector<ll>(m)),col(n,vector<ll>(m)),miring_atas(n,vector<ll>(m,0)),miring_bawah(n,vector<ll>(m,0));
    for(int i = 0; i < n; i++){
        string s = "";
        for(int y = 0; y < m; ++y){
            s += v[i][y];
        }
        row[i] = check_longest(s);
    }
    for(int i = 0; i < m; i++){
        string s = "";
        for(int y = 0; y < n; y++){
            s += v[y][i];
        }
        vector<ll> dp =  check_longest(s);
        for(int y = 0; y < n; ++y){
            col[y][i] = dp[y];
        }
    }
    for(int i = 0; i < n; ++i){
        string s = "";
        for(int r = i, c = 0; r >= 0 && c < m; ++c, r--) s += v[r][c];
        vector<ll> dp = check_longest(s);
        for(int k = 0, r = i, c = 0; r >= 0 && c < m; k++, r--, c++) miring_atas[r][c] = dp[k];
    }

    for(int i = 0; i < m; ++i){
        string s = "";
        for(int r = n - 1, c = i; r >= 0 && c < m; r--,++c) s += v[r][c];
        vector<ll> dp = check_longest(s);
        for(int k = 0, r = n - 1, c = i; r >= 0 && c < m; k++, r--, c++) miring_atas[r][c] = dp[k];
    }
    
    for(int i = 0; i < n; ++i){
        string s = "";
        for(int r = i, c = 0; r < n && c < m; ++r, ++c) s += v[r][c];
        vector<ll> dp = check_longest(s);
        for(int k = 0, r = i, c = 0; r < n && c < m; ++r, ++c, ++k) miring_bawah[r][c] = dp[k];
    }
   for(int i = 1; i < m; ++i){
        string s = "";
        for(int r = 0, c = i; r < n && c < m; ++r, ++c) s += v[r][c];
        vector<ll> dp = check_longest(s);
        for(int k = 0, r = 0, c = i; r < n && c < m; ++r, ++c, ++k) miring_bawah[r][c] = dp[k];
    }
    ll ans = -1;
    map<ll,ll> mp;
    for(int i = 0; i < n; ++i){
        for(int y = 0; y < m; ++y){
            ll val = min({row[i][y],col[i][y],miring_atas[i][y],miring_bawah[i][y]});
            if(ans == -1) ans = val;
            else ans = max(ans,val);
            mp[val]++;
        }
    }
    cout << mp[ans] << " " << ans;
}

int main() {
    gg;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}