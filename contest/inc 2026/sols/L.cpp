#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<char,ll> m = {{'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5}};
ll incnv(vector<vector<ll>> &v,ll r,char c){
    ll val = 0;
    if(m[c] >= 3){
        for(int i = 3; i < m[c]; ++i){
            if(v[r][i] == 1) ++val;
        }
    }else{
        for(int i = 2; i > m[c]; --i){
            if(v[r][i] == 1)++val;
        }
    }
    v[r][m[c]] = 1;
    return val;
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> v(n,vector<ll>(6));
    vector<ll> q;
    ll sum = 0;
    for(int i = 0; i < m; ++i){
        ll a;
        char b;
        cin >> a >> b;
        ll p = incnv(v,a - 1, b);
        q.push_back(p);
        sum += p;
    }
    sort(q.rbegin(),q.rend());
    for(int i = 0; i < k; ++i){
        sum -= q[i];
    }
    cout << sum;
}