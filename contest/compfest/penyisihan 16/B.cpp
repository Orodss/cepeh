#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define lesgoo ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug(a) cout << "DEBUG: " << a <<"\n"
#define debug1(a, b) cout << "DEBUG: " << a << ", " << b << "\n";
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

map<char, pair<int, int>> arah = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
int n, m;
int cnt_visit = 0;

void dfs(pair<int, int> cur, vector<string> dir,  vector<vector<bool>> &visited) {
    cnt_visit++;
    visited[cur.first][cur.second] = 1; 
    //debug1(cur.first, cur.second);
    int nexti = cur.first + arah[dir[cur.first][cur.second]].first;
    int nextj = cur.second + arah[dir[cur.first][cur.second]].second;
    
    //debug1(nexti, nextj);
    if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) return;
    if (!visited[nexti][nextj]) {
        dfs({nexti, nextj}, dir, visited);
    }   
}

void solve(){  
    cin >> n >> m;
    vector<string> dir (n);
    for(int i = 0; i < n; i++){
        cin >> dir[i];
    }

    int res = 0;
    vector<vector<bool>> visited(n, vector<bool> (m, 0));
    vector<vector<int>> in (n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int nexti = i + arah[dir[i][j]].first;
            int nextj = j + arah[dir[i][j]].second;
            if(nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
            else{
                in[nexti][nextj]++;
            }
        }
    }
    vector<pair<int,pair<int,int>>> qq;
    for(int i = 0; i < n; ++i){
        for(int q = 0; q < m; ++q){
            int x = arah[dir[i][q]].first;
            int y = arah[dir[i][q]].second;
            qq.push_back({in[x][q],{x,q}});
        }
    }
    sort(qq.begin(),qq.end());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                dfs({i, j}, dir, visited);
                res++;
            }
        }
    }
    
    cout << res << "\n";
}

signed main(){
    lesgoo;

    solve();
}