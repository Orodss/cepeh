#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int k,s,n;
    cin >> k >> s >> n;
    ll sum = s * k;
    if(sum > n) cout << "NO";
    else{
        if(s == 1){
            if(((n - sum) & 1) && (n - sum > k - 2)) cout << "NO";
            else cout << "YES";
        }else{
            if(k > 2)cout << "YES";
            else cout << "NO";
        }
    }
}