
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 998244353;

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll mx = 0;
    vector<ll> v(n);

    for (auto &x : v) {
        cin >> x;
        mx = max(mx, x);
    }

    // Sieve
    vector<bool> pr(mx + 1, true);
    pr[0] = false;
    if (mx >= 1) pr[1] = false;

    for (ll i = 2; i * i <= mx; ++i) {
        if (pr[i]) {
            for (ll y = i * i; y <= mx; y += i) {
                pr[y] = false;
            }
        }
    }

    vector<ll> prime;

    for (ll i = 2; i <= mx; i++) {
        if (pr[i]) prime.push_back(i);
    }
    vector<ll> freq(mx + 1, 0);

    for (auto x : v) {
        freq[x]++;
    }
    vector<ll> cnt(mx + 1, 0);

    for (ll d = 1; d <= mx; d++) {
        for (ll j = d; j <= mx; j += d) {
            cnt[d] += freq[j];
        }
    }

    ll ans = 1;

    for (auto p : prime) {
        ll fc = p;
        ll exponent = 0;

        while (fc <= mx) {
            ll c = cnt[fc];
            exponent += c * (c - 1) / 2;
            if (fc > mx / p) break;
            fc *= p;
        }

        ans = ans * modpow(p, exponent) % mod;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
