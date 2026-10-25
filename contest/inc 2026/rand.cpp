#include <bits/stdc++.h>
using namespace std;


void check(vector<int> v,set<int> s,int &cnt){
    for(auto x : s){
        vector<bool> q(5, false);
        for(int i = 0; i < 5; i++){
            if(v[i] == x) q[i] = true;
            if(i > 0){
                if(q[i] && q[i - 1]) return;
            }
        }
        ++cnt;
    }
    for(auto x : v) cout << x << " ";
    cout << "\n";
}

int main(){
    int cnt = 0;
    int sum = 0;
    for(int a = 1; a<= 3; ++a){
        for(int b = 1; b <= 3; ++b){
            for(int c = 1; c <= 3; ++c){
                for(int d = 1; d <= 3; ++d){
                    for(int e = 1; e <= 3; ++e){
                        vector<int> v = {a,b,c,d,e};
                        set<int> s = {a,b,c,d,e};
                        check(v,s, cnt);
                        ++sum;
                    }
                }
            }
        }
    }
    cout << cnt << " " << sum;
}