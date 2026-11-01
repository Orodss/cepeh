#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll sum = a + b + c;
        ll mn = min({a,b,c});
        if(mn == a){
            while(sum--) cout << 'S';
        }else if(mn == b){
            while(sum--) cout << 'P';
        }else{
            while(sum--) cout << 'R';
        }
        cout << "\n";
    }
}