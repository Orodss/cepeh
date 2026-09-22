#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(),v.end());
    ll m = 0, s = 0;
    for(int i = 0; i < n; i++){
        if(a >= v[i]){
            a += c;
            m++;
        }else if(a + b >= v[i]){ 
            a += c;
            s++;
            m++;
        }else{
            break;
        } 
    }
    cout << m << " " << s;
}