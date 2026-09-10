#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,m;
    cin >> n >> m;
    ll tmp = 1;
    for(ll i = 2; i * i <= 1e9; ++i){
        while(n % i == 0 && m % i == 0){
            tmp *= i;
            n /= i;
            m /= i;
        }
    }
    if(m % n == 0){
        tmp *= n;
        m /= n;
        n = 1;
    }else if(n % m == 0){
        tmp *= m;
        n /= m;
        m = 1;
    }
    cout << (n * (tmp + 1LL) * m * (tmp + 1LL)) - ((n * tmp) * (m * tmp));
}