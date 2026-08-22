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
vector<ll> pr;
vector<ll> lf(maxn + 1);
vector<ll> totient(maxn + 1, 0);
vector<ll> prime(maxn + 1, true);
ll find_totient(ll n){
    ll res = n;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0) n /= i;
        }
    }

    if(n > 1) res -= res / n;
    return res;
}
void linear(){
    for(ll i = 2; i <= maxn; ++i){
        if(lf[i] == 0){
            lf[i] = i;
            pr.pb(i);
        }
        for(ll y = 0; y < pr.size(); ++y){
            if(i * y > maxn) break;
            lf[i * pr[y]] = y;
            if(pr[y] == i){
                break;
            }
        }
    }
}

void linear_totient(){
    for(ll i = 2; i <= maxn; ++i){
        if(prime[i]){
            pr.pb(i);
            totient[i] = i - 1;
        }
        for(ll x : pr){
            if(x * i > maxn) break;
            pr[x * i] = false;
            if(i % x == 0){
                totient[i * x] = find_totient(i) * x;
                break;
            }else{
                totient[i * x] = find_totient(i) * (x - 1);
            }
        }
    }
}
int main(){
}