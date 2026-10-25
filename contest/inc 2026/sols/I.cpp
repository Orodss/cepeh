#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 998244353;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = m;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] % mod + dp[i - 2] * (m - 1) % mod) % mod;
    }
    cout << ((dp[n] * m) % mod - (m * (m - 1) % mod) + mod) % mod;
}