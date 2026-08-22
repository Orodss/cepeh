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


const ll maxn = 1e6;
const ll mod = 998244353;
vl fact(maxn + 1);


ll modpow(ll a,ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

ll modiv(ll a){
    return modpow(a, mod - 2);
}

ll combin(ll a,ll b){
    ll d = fact[b] * fact[a - b] % mod;
    return fact[a] * modiv(d) % mod; 
}

void solve(){
    ll n;
    cin >> n;
    vl v(n);
    ll sum = 0;
    map<ll,ll> m;
    for(ll &x : v){
        cin >> x;
        sum += x;
        ++m[x];
    }
    
    ll res = 1;
    for(auto x : v){
        res = res * combin(sum, x) % mod;
        sum -= x;
    }

    for(auto k: m){
        res = res * modiv(fact[k.second]) % mod;
    }
    cout << res;
}

int main() {
    gg;
    fact[0] = 1;
    for(ll i = 1; i <= maxn; ++i){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    solve();
}