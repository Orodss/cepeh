#include <bits/stdc++.h>
using namespace std;
bool pal(int l,int r,string a){
    while(l < r){
        if(a[l] != a[r]) return false;
        ++l; --r;
    }
    return true;
}
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.size() - 1; ++i){
        if(pal(0,i,a) && pal(i + 1,a.size() - 1,a)){
            for(int y = 0; y <= i; ++ y) cout << a[y];
            cout << " ";
            for(int y =i + 1; y < a.size(); ++y) cout << a[y];
            return 0;
        }
    }
    cout << "NO";
}