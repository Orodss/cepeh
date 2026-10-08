#include <bits/stdc++.h>
using namespace std;

#define gg ios::sync_with_stdio(false); cin.tie(nullptr);

template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double

#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vl>
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define fr first
#define sc second

#define ml map<ll,ll>
#define mc map<char,ll>

#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(x.rbegin(),x.rend());

const ll INF = LLONG_MAX;
const ll NINF = LLONG_MIN;

#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

bool check(ll x, vector<pair<ll,ll>>& v, ll n, ll k){
    for(int i = 0; i < n; i++){
        if(x <= v[i].first) continue;
        if(v[i].second == -1) return false;

        ll need = v[i].second + x - v[i].first;

        if(need > k) return false;

        k -= need;
    }

    return true;
}

void solve(){
    ll n,k;
    cin >> n >> k;

    vector<pair<ll,ll>> v;

    for(int i = 0; i < n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        ll sum = a + b + c;
        ll cost;
        if(a == b && b == c){
            cost = -1;
        }
        else if(a > b || a > c || b > c){
            cost = 0;
        }
        else{
            cost = 2 * min(b - a, c - b) + 2;
        }
        v.push_back({sum,cost});
    }
    sort(v.begin(),v.end());
    ll l = v[0].first;
    ll r = l + k;
    ll ans = l;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(mid,v,n,k)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main(){
    gg;
    int t;
    cin >> t;
    while(t--)
        solve();
}