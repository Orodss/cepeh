#include<bits/stdc++.h>
using namespace std;

#define int long long
#define uint unsigned long long
#define lesgoo ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug(a) cout << "DEBUG: " << a <<"\n"
#define debug1(a, b) cout << "DEBUG: " << a << ", " << b << "\n";
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    int mx = -1;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 1; ++i){
        sum += arr[i + 1] - arr[i];
        mx = max(mx,arr[i + 1] - arr[i]);
    }
    while(q--){
        int m; cin >> m;
        if(sum + mx <= m){
            cout << mx + (m - (sum + mx)) << "\n";
            continue;
        }
        int l = 0;
        int r = LONG_LONG_MAX;
        int minn = LONG_LONG_MAX;
        while(l <= r){
            int k = l + (r - l) / 2;

            int sum = k;
            for(int i = 0; i < n-1; i++){
                if(arr[i]+k < arr[i+1]){
                    sum += k;
                }else{
                    sum += (arr[i+1] - arr[i]);
                }
            }

            // debug1(k, sum);
            if(sum < m){
                l = k+1;
            }else if(sum >= m){
                minn = min(minn, k);
                r = k-1;
            }
        }

        cout << minn << "\n";
    }
}

signed main(){
    lesgoo;

    solve();
}