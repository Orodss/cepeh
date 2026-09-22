#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    vector<ll> v = {200,188,200,300,188,300,200};
    for(auto &x : v) cout << x << " ";
    cout << "\n";
    map<ll,ll> m;
    vector<ll> tot;
    for(auto &x : v){
        if(m[x] == 0) tot.push_back(x);
        m[x]++;
    }
    sort(tot.begin(),tot.end());

    for(auto &x : v){
        x = lower_bound(tot.begin(),tot.end(),x) - tot.begin();
    }
    for(auto &x : v) cout << x << " ";
}