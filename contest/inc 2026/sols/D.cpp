#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    ll cnt = 0;
    ll v;
    ll idx;
    bool ans = true;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(a <= n){
            ++cnt;
            v = a;
            idx = i + 1;
            if(idx != v || v + v <= n) ans = false;
        }
    }
    if(cnt == 0){
        cout << "Tresno";
    }else{
        if(ans){
            if(cnt & 1) cout << "Fausta";
            else cout << "Tresno";
        }else{
            cout << "Draw";
        }
    }
}