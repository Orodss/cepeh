#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> v1(n),v2(n);
    for(auto &x : v1) cin >> x;
    for(auto &x : v2) cin >> x;
    set<ll> s1,s2;
    vector<ll> q;
    q.push_back(-1);
    for(int i = 0; i < n; i++){
        if(s1.find(v1[i]) != s1.end() || s2.find(v2[i]) != s2.end()){
            q.push_back(i - 1);
            s1.clear();
            s2.clear();
        }
        s1.insert(v1[i]);
        s2.insert(v2[i]);
    }
    q.push_back(n - 1);
    for(auto x : q) cout << x << " ";
}