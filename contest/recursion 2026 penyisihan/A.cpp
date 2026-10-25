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

vl pattern(vl &v1, vl &v2, int skip){
    int m = v1.size();
    int idx = 0;

    while(idx < m && v1[idx] == v2[idx])
        idx++;

    if(idx == m) return {};

    vl p;

    for(int i = 0; i < m; i++){
        if(i == idx) continue;

        if(skip == 0) p.pb(v1[i]);
        else p.pb(v2[i]);
    }

    return p;
}

bool valid(vl &v1, vl &v2){
    int l1 = 0, l2 = 0;

    while(l1 < v1.size() && l2 < v2.size()){
        if(v1[l1] == v2[l2])
            l1++;

        l2++;
    }

    return l1 == v1.size();
}

void solve(){
    int n, m;
    cin >> n >> m;

    vvl v(n, vl(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int a = 0; a < 3; a++){
        for(int b = a + 1; b < 3; b++){
            for(int k = 0; k < 2; k++){
                vl p = pattern(v[a], v[b], k);

                if(p.size() != m - 1) continue;
                if(!valid(p, v[a]) || !valid(p, v[b])) continue;

                int ans = -1, cnt = 0;

                for(int i = 0; i < n; i++){
                    if(!valid(p, v[i])){
                        ans = i + 1;
                        cnt++;

                        if(cnt > 1) break;
                    }
                }

                if(cnt == 1){
                    cout << ans << en;
                    return;
                }
            }
        }
    }

    cout << -1 << en;
}

int main(){
    gg;

    int t = 1;
    cin >> t;

    while(t--) solve();
}