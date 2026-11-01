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
    ll n,m;
    cin >> n>> m;
    string s1,s2;
    cin >> s1 >> s2;
    map<char,ll> mp,mp2;
    multiset<char> ss1,ss2;
    for(auto x : s1){
        if(x == 's'){
            mp['s']++;
            if(mp['s'] > 1)ss1.insert(x);
        }else if(x == 'i'){
            mp['i']++;
            if(mp['i'] > 1)ss1.insert(x);
        }else if(x == 'x'){
            mp['x']++;
            if(mp['x'] > 1)ss1.insert(x);
        }else{
            ss1.insert(x);
        }
    }
    for(auto x : s2){
        ss2.insert(x);
    }
    for(auto x : s2){
        if(ss1.find(x) != ss1.end()){
            ss1.erase(ss1.find(x));
            ss2.erase(ss2.find(x));
        }else{
            cout << "NO\n";
            return;
        }
    }
    if(mp['s'] == 0 || mp['i'] == 0 || mp['x'] == 0){
        cout << "NO\n";
    }else if(ss1.size() == 0 && ss2.size() == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main() {
    gg;
    int t = 1;
    cin >> t;
    while(t--) solve();
}