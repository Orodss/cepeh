#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a = (2 * 100 + 1) * (100 + 1) * (100) / 6;
    ll b = (100) * (101) / 2;
    b *= b;
    cout << abs (a - b);
}