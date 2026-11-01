#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    ll x = 1;
    ll val = 0;
    while(x <= n){
        if(!(x & n)){
            val += x;
        }
        x *= 2LL;
    }
    x = 1;
    while(x <= n){
        if(x & 1){
            if(val == 0) val += x;
            break;
        }
        x *= 2;
    }
    cout << val;
}