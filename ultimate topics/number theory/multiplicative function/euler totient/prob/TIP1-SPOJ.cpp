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

const ll maxn = 1e7;

vector<ll> phi(maxn + 1);
vector<ll> pr;
vector<bool> prime(maxn + 1, true);
vector<ll> ans(maxn + 1);


bool cmp(ll a,ll b){
    vector<int> v(10, 0);
    while(a > 0){
        v[a % 10]++;
        a /= 10;
    }
    while(b > 0){
        v[b % 10]--;
        b /= 10;
    }
    for(int i = 0; i <= 9; ++i) if(v[i] != 0) return false;
    return true;
}

void solve(){
    ll m;
    cin >> m;
    if(m <= 2 || ans[m - 1] == 0) cout << "No solution.\n";
    else cout << ans[m - 1] << "\n";
}

int main() {
    gg;
    for(ll i = 2; i <= maxn; ++i){
        if(prime[i]){
            pr.push_back(i);
            phi[i] = i - 1;
        }
        for(ll x : pr){
            if(x * i > maxn) break;
            prime[x * i] = false;
            if(i % x == 0){
                phi[i * x] = phi[i] * x;
                break;
            }else{
                phi[i * x] = phi[i] * (x - 1);
            }
        }
    }

    ll N = 0;
    for(int i = 3; i <= maxn; ++i){
        if(cmp(i,phi[i])){
            if(N == 0){
                N = i;
            }else{
                ll N1 = N,phi1 = phi[N1], N2 = i, phi2 = phi[N2];
                if(N1 * phi2 >= N2 * phi1){
                    N = i;
                }
            }
        }
        ans[i] = N;
    }

    int t = 1;
    cin >> t;
    while(t--) solve();
}