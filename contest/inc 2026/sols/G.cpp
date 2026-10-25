#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define f0r(a, b, c) for (ll a = b; a < c; ++a)
#define en "\n"

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<ll> sum(n + 1);

    f0r(i, 1, n){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        sum[i] = 1;
    }

    using Q = pair<ll, ll>;
    priority_queue<Q, vector<Q>, greater<Q>> q; // jmlh orng, vrtx | urut terkecil
    f0r(i, 1, n + 1){
        if (g[i].size() == 1){
            q.push({sum[i], i});
        }
    }
    ll move = (n - 1);
    cout << move * 2 << en;
    while (move){
        auto [s, cur] = q.top();
        q.pop();

        for (ll next : g[cur]){
            sum[next] += sum[cur];

            // auto it= find(g[cur].begin(), g[cur].end(), next);
            // g[cur].erase(it);

            auto it = find(g[next].begin(), g[next].end(), cur);
            g[next].erase(it);

            if (g[next].size() == 1){
                q.push({sum[next], next});
            }

            cout << "M " << cur << " " << next << en;
            cout << "A " << cur << en;
        }
        --move;
        // cout<<move<<en;
    }
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}