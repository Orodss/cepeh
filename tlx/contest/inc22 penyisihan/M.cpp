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
    for(auto &x : v) cin >> x;
    ll mx = 0;
    ll l = 0;
    for(int i = 0; i + 2 < n; i+=2){
        if(abs(v[i] - v[i + 2]) != 2 && abs(v[i] - v[i + 2]) != 0){
            mx = max(mx,i + 2 - l);
            // dbg(l,i + 1);
            l = i + 1;
        }

    }
    // dbg(l,n - 1);
    mx = max(mx,n - l);
    ll r = n - 1;
    ll left = n - 1;
    if(n % 2 == 0){
        --left;
    }
    for(int i = left; i - 2 >= 0; i -= 2){
        if(abs(v[i] - v[i - 2]) != 2 && abs(v[i] - v[i - 2]) != 0){
            mx = max(mx,r - i + 2);
            // dbg(i - 1,r);
            r = i - 1;
        }
    }
    // dbg(0,r + 1);
    mx = max(mx,r + 1);
    cout << mx;
}

int main() {
    gg;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}