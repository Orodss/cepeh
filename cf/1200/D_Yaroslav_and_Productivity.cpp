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
    vector<ll> v(n);
    vector<ll> q(m);
    for(auto &x : v) cin >> x;
    for(auto &x : q) cin >> x;
    vector<ll> neg(n + 1,0),pos(n + 1,0);
    for(int i = 1; i <= n; ++i){
        pos[i] = pos[i - 1];
        neg[i] = neg[i - 1]; 
        if(v[i - 1] > 0) pos[i] += v[i - 1];
        else neg[i] += abs(v[i - 1]);
    }
    sort(q.rbegin(),q.rend());
    ll cnt = 0;
    ll ans = 0;
    for(int i = 0; i < m - 1; ++i){
        ll negs = 0;
        ll poss = 0;
        negs = neg[q[i]] - neg[q[i + 1]];
        poss = pos[q[i]] - pos[q[i + 1]];
        ans += (max(negs,poss) - min(negs,poss));
    }
    ans += max(neg[q[m - 1]],pos[q[m - 1]]) - min(neg[q[m -1]],pos[q[m - 1]]);
    for(int i = q[0] + 1; i <= n; ++i) ans += v[i - 1];
    cout << ans << "\n";
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}