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
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> prime(3200,true);
    prime[1] = false;
    for(int i = 2; i * i <= 3200; ++i){
        if(prime[i]){
            for(int y = i * i; y <= 3200; y += i){
                prime[y] = false;
            }
        }
    }
    map<vector<ll>,ll> m;
    vector<vector<ll>> od(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        ll x = v[i];
        for(int y = 2; y * y <= x; ++y){
            if(prime[y] && x % y == 0){
                ll cnt = 0;
                while(x % y == 0){
                    ++cnt;
                    x /= y;
                }
                if(cnt & 1)od[i].pb(y);
            }
        }
        if(x > 1) od[i].pb(x);
        // dbg(od[i]);
        m[od[i]]++;
    }
    ll ans = 0;
    set<ll> s;
    vector<ll> q;
    for(int i = 0; i < n; ++i){
        for(auto x : od[i]){
            if(s.find(x) == s.end()){
                s.insert(x);
            }else{
                s.erase(x);
            }
        }
        if(s.size() > 7) continue;
        // dbg(q);
        ans += m[vector<ll>(s.begin(),s.end())];
    }

    cout << ans << "\n";
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}