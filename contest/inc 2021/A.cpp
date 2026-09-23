#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<bool> v(1001,false);
    int n; cin >> n; int sus = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(v[abs(a)]){
            if(a < 0) v[abs(a)] = false;
            else ++sus;
        }else{
            if(a > 0) v[abs(a)] = true;
            else ++sus;
        }
    }
    cout << sus;
}