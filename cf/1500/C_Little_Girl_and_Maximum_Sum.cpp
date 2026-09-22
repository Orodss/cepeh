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

vector<ll> bit;
void add(ll idx,ll val){
    for(; idx < bit.size(); idx += idx & -idx){
        bit[idx] += val;
    }
}

ll query(ll idx){// sum [1...idx]
    ll res = 0;
    for(; idx > 0; idx -= idx & -idx) res += bit[idx];
    return res;
}

void solve(){
    ll n,q;
    cin >> n >> q;
    bit.resize(n + 1);
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    while(q--){
        ll l,r;
        cin >> l >> r;
        add(l,1);
        if(r+1 <= n) add(r + 1, -1);
    }
    // dbg(bit);
    vector<ll> p;
    for(int i = 1; i <= n; i++){
        p.push_back(query(i));
    }
    sort(p.rbegin(),p.rend());
    sort(v.rbegin(),v.rend());
    ll ans = 0;
    // dbg(p);
    for(int i = 0; i < n; ++i){
        if(p[i] == 0) break;
        ans += p[i] * v[i];
    }
    // dbg(q,v);
    cout << ans;
}

int main() {
    gg;
    solve();
}