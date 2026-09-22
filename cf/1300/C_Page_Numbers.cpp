#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string a;
    cin >> a;
    map<ll,ll> m;
    vector<ll> v;
    string temp = "";
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != ','){
            temp += a[i];
        }else{
            m[(ll)stoi(temp)]++;
            if(m[(ll)stoi(temp)] == 1) v.push_back(stoi(temp));
            temp = "";
        }
    }

    if(m[stoi(temp)] == 0) v.push_back(stoi(temp));
    sort(v.begin(),v.end());
    ll l = -1,r = -1;
    for(ll i = 0; i < v.size(); ++i){
        if(i == 0){
            l = v[i];
            r = l;
        }else{
            if(v[i] - v[i - 1] == 1) r = v[i];
            else{
                if(l != r) cout << l << "-" << r << ",";
                else cout << l << ",";
                l = v[i];
                r = v[i];
            }
        }
    }
    if(l == r) cout << l;
    else cout << l << "-" << r ;
}