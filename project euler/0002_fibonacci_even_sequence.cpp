#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll prev1 = 1, prev2 = 2;
    ll sum = 2;
    while(true){
        ll nw = prev1 + prev2;
        if(nw > 4000000) break;
        if(nw % 2 == 0) sum += nw;
        prev1 = prev2;
        prev2 = nw;
    }
    cout << sum;
}