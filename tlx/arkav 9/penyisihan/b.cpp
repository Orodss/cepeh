#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool valid(string a,int idx){
    if(a[idx] == a[idx + 2] && a[idx + 1] == 'g') return true;
    return false;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        bool ans = true;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o'){
                if(!valid(s,i)){
                    ans = false;
                    break;
                }
                i += 2;
            }
        }
        if(ans) cout << "Begenagar\n";
        else cout << "Sagalagah\n";
    }
}