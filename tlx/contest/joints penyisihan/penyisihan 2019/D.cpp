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

map<char,ll> mp = {{'A',1},{'B',2},{'C',4},{'D',8},{'E',16}};

void dfs(ll x,ll y,vector<vector<bool>> &vis,vector<vector<char>> &c,ll &sum){
    vis[x][y] = true;
    sum += mp[c[x][y]];
    for(int i = 0; i < 4; i++){
        ll xx = x + dx[i];
        ll yy = y + dy[i];
        if(xx >= 0 && yy >= 0 && xx < vis.size() && yy < vis[0].size() && !vis[xx][yy] && c[xx][yy] != '#'){
            vis[xx][yy] = true;
            dfs(xx,yy,vis,c,sum);
        }
    }
}

void solve(){
    ll n,m,k; cin >> n >> m >> k;
    vector<vector<char>> c(n,vector<char>(m)); 
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int y = 0; y < m; ++y){
            c[i][y] = s[i][y];
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<ll> ans;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < m; ++y){
            if(c[i][y] != '#' && !vis[i][y]){
                ll sum = 0;
                dfs(i,y,vis,c,sum);
                ans.push_back(sum);
                // dbg(sum,i,y);
            }
        }
    }
    sort(ans.rbegin(),ans.rend());
    ll sum = 0;
    for(int i = 0; i < min(k,n); ++i) {
        sum += ans[i];
    }
    cout << sum;
}

int main() {
    gg;
    solve();
}