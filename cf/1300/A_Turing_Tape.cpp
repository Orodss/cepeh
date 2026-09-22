#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    string a;
    getline(cin, a);
    ll prev = 0;
    for(char x : a){
        ll ascii = (ll)x;
        ll rev = 0;
        for (int i = 0; i < 8; i++) {
            rev <<= 1;
            rev |= (ascii & 1);
            ascii >>= 1;
        }
        // cout << rev << " ";
        ll ans = (prev - rev + 256) % 256;
        cout << ans << "\n";
        prev = rev;
    }
}