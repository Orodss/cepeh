#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll ans = abs(b - c);
        if(a <= 3){
            cout << 1 << "\n";
            continue;
        }
        ll mv1,mv2;
        if(c > b){
            mv1 = c - b;
            mv2 = b + a - c;
        }else{
            mv1 = b - c;
            mv2 = a - b + c;
        }

        cout << d + min(mv1,mv2) << "\n";
    }
}