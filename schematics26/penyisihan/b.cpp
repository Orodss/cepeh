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


ll check_longest(string s){
    ll n = s.size();
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    for(int i = n - 1; i >= 0; i--){
        dp[i][i] = 1;
        for(int y = i + 1; y < n; ++y){
            if(s[i] == s[y]) dp[i][y] = dp[i + 1][y - 1] + 2;
            else dp[i][y] = max(dp[i + 1][y],dp[i][y - 1]);
        }
    }
    return dp[0][n - 1];
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
    vector<ll> row(n),col(m);
    vector<vector<ll>> miring_atas(n,vector<ll>(m,0)),miring_bawah(n,vector<ll>(m,0));

    for(int i = 0; i < n; i++){
        string s = "";
        for(int y = 0; y < m; ++y){
            s += v[i][y]; // semua kolom utk row i
        }
        row[i] = check_longest(s);
    }
    for(int i = 0; i < m; ++i){
        string s = "";
        for(int y = 0; y < n; ++y){
            s += v[y][i];
        }
        col[i] = check_longest(s);
    }
    for(int i = 0; i < n; i++){
        ll c = 0;
        ll r = i;
        string s = "";
        while(c < m && r >= 0){
            s += v[r][c];
            r--;
            c++;
        }
        miring_atas[i][0] = check_longest(s);

    }
    for(int i = 1; i < m; ++i){
        ll r = n - 1;
        ll c = i;
        string s = "";
        while(r >= 0 && c < m){
            s += v[r][c];
            r--;
            c++;
        }
        miring_atas[n - 1][i] = check_longest(s);
    }

    for(int i = 0; i < n; i++){
        ll r = i;
        ll c = 0;
        string s = "";
        while(c < m && r < n){
            s += v[r][c];
            r++;
            c++;
        }
        miring_bawah[i][0] = check_longest(s);
    }

    for(int i = 1; i < m; ++i){
        ll r = 0;
        ll c = i;
        string s = "";
        while(r < n && c < m){
            s += v[r][c];
            ++r;
            ++c;
        }
        miring_bawah[0][i] = check_longest(s);
        // dbg(s,0,i,miring_bawah[0][i]);
    }
    ll ans = -1;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++){
        ll val;
        for(ll y = 0; y < m; ++y){
            val = min(row[i],col[y]);
            ll r1 = i - min(i,y),c1 = y - min(i,y); // miring bawah
            ll r2 = i + min(n - i - 1,y),c2 = y - min(n - i - 1,y);
            val = min(val,min(miring_bawah[r1][c1],miring_atas[r2][c2]));
            // dbg(i,y,row[i],col[y],miring_bawah[r1][c1],miring_atas[r2][c2],val);
            mp[val]++;
            if(ans == -1) ans = val;
            else ans = max(ans,val);
        }
    }
    cout << mp[ans] << " "<< ans;
}

int main() {
    gg;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}