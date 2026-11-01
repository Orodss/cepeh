#include <bits/stdc++.h>
using namespace std;

#define gg                       \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// output pair with cout
// usage example cout << p; with p as a pair
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}

// print container
template <typename T_container,
          typename T = typename enable_if<
              !is_same<T_container, string>::value,
              typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// debug printing
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

// debug macro, enable the local to use
// #define LOCAL
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
#define ml map<ll, ll>
#define mc map<char, ll>

// sort
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(x.rbegin(), x.rend());

// edges
const ll INF = LLONG_MAX;
const ll NINF = LLONG_MIN;

// output
#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char move[] = {'D', 'R', 'U', 'L'};

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if (s[i - 1] == '1')
            ++pref[i];
        else
            --pref[i];
    }
    ll ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        ll le = pref[i - 1];
        if (pref[n] == 0)
        {
            if (le * (pref[n] - le) < 0)
                ans += k;
        }
        else
        {
            if (pref[n] > 0)
            {
                ll tot = pref[n], all = tot * k;
                ll h = floor(double(-le) / double(tot));
                if (-le % tot == 0)
                    --h;
                if (h >= 0)
                    ans += min(k - 1, h) + 1;
                ll mx = max((ll)0, all);
                ll l = ceil(double(mx - le) / double(tot));
                if ((mx - le) % tot == 0)
                    ++l;
                l = max((ll)0, l);
                if (l < k)
                    ans += k - l;
            }
            else
            {
                ll tot = -pref[n];
                ll all = -tot * k;
                ll h = floor(double(le) / double(tot));
                if (le % tot == 0)
                    --h;

                if (h >= 0)
                    ans += min(k - 1, h) + 1;
                ll l = ceil(double(le - all) / double(tot));
                if ((le - all) % tot == 0)
                    ++l;
                l = max(0LL, l);
                if (l < k)
                    ans += k - l;
            }
        }
    }
    cout << ans;
}

int main()
{
    gg;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}