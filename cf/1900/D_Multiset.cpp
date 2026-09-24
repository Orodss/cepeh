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

const ll maxn = 1e6;
vector<ll> bit(maxn + 1,0);
void add(ll a, ll v){
    for(; a <= maxn; a += a & -a){
        bit[a] += v;
    }
}
ll sum(ll idx){
    ll pw = 1;
    ll pos = 0;
    while((pw << 1) <= maxn) pw <<= 1;
    for(; pw > 0; pw>>=1){
        ll nxt = pos + pw;
        if(nxt <= maxn && bit[nxt] < idx){
            pos = nxt;
            idx -= bit[nxt];
        }
    }
    return pos + 1;
}
void solve(){
    ll n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        add(a,1);
    }
    for(int i = 0; i < q; ++i){
        ll a;
        cin >> a;
        if(a > 0) add(a,1);
        else{
            add(sum(abs(a)), -1);
        }
    }
    if(sum(1) != maxn + 1) cout << sum(1);
    else cout << 0;
}

int main() {
    gg;
    solve();
}