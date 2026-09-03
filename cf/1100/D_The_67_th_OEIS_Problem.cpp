#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int tc; cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        ll res = 1;
        for(int i = 0; i < n; ++i){
            cout << (2 * i + 1)  * (2 * i + 3) << " ";
        }
        cout << "\n";
    }
}