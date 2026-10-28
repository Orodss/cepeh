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
    ll n;
    cin >> n;
    auto a = [] (ll a,ll b){
        if(a == b) return 2;
        return 1;
    };
    vector<ll> v1(n),v2(n);
    for(auto &x : v1) cin >> x;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v2[i];
        if(i > 0){
            sum += a(v2[i],v1[i - 1]) + a(v1[i],v2[i - 1]);
        }
    }
    sum += a(v1[n - 1],v2[n - 1]);
    ll ans = sum;
    for(int i = 0; i < n - 1; i++){
        sum = sum + a(v1[i],v2[i]) - a(v1[i],v2[i + 1]);
        ans = max(ans,sum);
        dbg(sum);
    }
    cout << ans << "\n";
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}