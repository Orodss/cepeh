#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct DSU{
    vector<int> parent, sz;
    int components;
    DSU(int n){
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(),parent.end(), 0);
        components = n;
    }
    //cari parent untuk set dimana elemen x berada
    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a,int b){
        ll para = find(a);
        ll parb = find(b);
        if(para == parb) return false;
        if(sz[para] < sz[parb]) swap(a,b);

        parent[parb] = para;
        sz[para] += sz[parb];

        components--;
    }

    bool same(int a,int b){
        return parent[a] == parent[b];
    }

    int size(int a){
        return sz[parent[a]];
    }
};


int main(){

}