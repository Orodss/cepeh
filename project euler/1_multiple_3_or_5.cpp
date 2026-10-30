#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n = 999;
    ll cnt3 = n / 3;
    ll cnt5 = n / 5;
    ll cnt15 = n / 15;
    ll sum3 = 3 * (cnt3 * (cnt3 + 1) / 2);
    ll sum5 = 5 * (cnt5 * (cnt5 + 1) / 2);
    ll sum15 = 15 * (cnt15 * (cnt15 + 1) / 2);
    cout << sum3 + sum5 - sum15;
}