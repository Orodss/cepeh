#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        v.push_back({a,i + 1});
    }
    sort(v.begin(),v.end());
    if(v.size() > 1){
        ll a = v[v.size()  -1].first - v[0].first;
        if(a % 2 != 0) {
            cout << "TIDAK SESUAI";
            return 0;
        }
        a /= 2;
        v[0].first += a;
        v[v.size() - 1].first -= a;
        for(int i = 1; i < v.size(); ++i){
            if(v[i].first != v[i - 1].first){
                cout << "TIDAK SESUAI";
                return 0;
            }
        }
        if(a == 0)cout << "SESUAI";
        else{
            cout << a << " " << v[v.size() - 1].second << " " << v[0].second;
        }
    }else{
        cout << "SESUAI";
    }
}