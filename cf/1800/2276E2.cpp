#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ll n;
        string s;
        cin >> n >> s;
        vector<vector<ll>> v(n,vector<ll>(10));
        vector<ll> cur(10,n);
        for(int i = n - 1; i >= 0; --i){
            cur[s[i] - '0'] = i;
            for(int y = 0; y < 10; y++){
                v[i][y] = cur[y];
            }
        }
        string s1=  "2025", s2 = "2026";
        vector<ll> d(n, 0), dd(n + 2);
        for(int i = 0; i < n; i++){
            ll l = 0;
            ll r25 = i, r26 = i;
            while(l < 4 && r25 < n){
                ll x = s1[l++] - '0';
                r25 = v[r25][x];
            }
            l = 0;
            while(l < 4 && r26 < n){
                ll x = s2[l++] - '0';
                r26 = v[r26][x];
            }
            d[i] += (n - i);
            dd[i + 1]--;
            if(r25 < r26){
                d[i] -= (r26 - r25);
                dd[r25 + 1]++;
                dd[r26 + 1]--;
            }
        }
        ll add = 0, sum = 0;
        for(int i = 0; i < n; i++){
            add += dd[i];
            sum += d[i] + add;
            cout << sum << " ";
        }
        cout << "\n";
    }
}