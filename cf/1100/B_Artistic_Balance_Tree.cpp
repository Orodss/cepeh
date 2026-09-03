#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int tc; cin >> tc;
    while(tc--){
        ll n,m;
        cin >> n >> m;
        ll odd = 0, even = 0;
        vector<ll> o,e;
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            ll a;
            cin >> a;
            if((i + 1) & 1) o.push_back(a);
            else e.push_back(a);
            sum += a;
        }
        for(int i = 0; i < m; ++i){
            ll a;
            cin >> a;
            if(a & 1) odd++;
            else even++;
        }
        sort(o.rbegin(),o.rend());
        sort(e.rbegin(),e.rend());
        for(int i = 0; i < min(odd,(ll)o.size()); ++i){
            if(o[i] < 0 && i > 0) break;
            sum -= o[i];
        }
        for(int i = 0; i < min(even,(ll)e.size()); ++i){
            if(e[i] < 0 && i > 0) break;
            sum -= e[i];
        }
        cout << sum << "\n";
    }
}