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
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll l = 0, r = 0;
    ll mx_length = -1;
    map<ll,ll> m;
    while(r < n){
        m[v[r]]++;
        if(m[v[r]] <= k){
            mx_length = max(mx_length,(r - l + 1));
            ++r;
        }else{
            while(l <= r && m[v[r]] > k){
                m[v[l]]--;
                ++l;
            }
            mx_length = max(mx_length,(r - l + 1));
            ++r;
        }
    }
    cout << mx_length << " ";
    m.clear();
    ll cnt = 0;
    l = 0, r = 0;
    while(r < n){
        m[v[r]]++;
        if(m[v[r]] <= k){
            if(mx_length == r - l + 1) ++cnt;
            // cout << l << " " << r << " " << (r - l + 1) << "\n";
            ++r;
        }else{
            // cout << "test\n";
            while(l <= r && m[v[r]] > k){
                m[v[l]]--;
                ++l;
            }
            // cout << l << " " << r << " " << (r - l + 1) << "\n";
            if(r - l + 1 == mx_length) ++cnt;
            ++r;
        }
    }
    cout << cnt;
}

int main() {
    gg;
    solve();
}