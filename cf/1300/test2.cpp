#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;

int n, q, B;
int a[MAXN];
bool act[MAXN];
int par[MAXN + 2];
int cntv[MAXN], lst[MAXN];
ll bitSum[MAXN];   // Fenwick: jumlah energi aktif
int bitCnt[MAXN];  // Fenwick: banyak kristal aktif
int LOG;

int findNext(int x) {
    int r = x;
    while (par[r] != r) r = par[r];
    while (par[x] != r) {
        int nx = par[x];
        par[x] = r;
        x = nx;
    }
    return r;
}

void addSum(int i, ll v) {
    for (; i <= n; i += i & -i) bitSum[i] += v;
}
ll getSum(int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i) s += bitSum[i];
    return s;
}
void addCnt(int i, int v) {
    for (; i <= n; i += i & -i) bitCnt[i] += v;
}
// cari posisi kristal aktif ke-k dari kiri
int kth(int k) {
    int pos = 0;
    for (int pw = LOG; pw > 0; pw >>= 1) {
        if (pos + pw <= n && bitCnt[pos + pw] < k) {
            pos += pw;
            k -= bitCnt[pos];
        }
    }
    return pos + 1;
}

void rebuild(int blk) {
    int st = blk * B + 1;
    int en = min(n, (blk + 1) * B);
    for (int i = en; i >= st; i--) {
        if (!act[i]) continue;
        ll t = (ll)i + a[i];
        if (t > n) {
            cntv[i] = 1;
            lst[i] = i;
            continue;
        }
        int y = findNext((int)t);
        if (y <= en) {
            cntv[i] = cntv[y] + 1;
            lst[i] = lst[y];
        } else {
            cntv[i] = 1;
            lst[i] = i;
        }
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    LOG = 1;
    while (LOG * 2 <= n) LOG *= 2;

    B = max(1, (int)sqrt((double)n));

    for (int i = 1; i <= n + 1; i++) par[i] = i;
    for (int i = 1; i <= n; i++) {
        act[i] = true;
        addSum(i, a[i]);
        addCnt(i, 1);
    }

    int numBlocks = (n - 1) / B + 1;
    for (int b = 0; b < numBlocks; b++) rebuild(b);

    string out;
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            if (!act[x]) continue;
            act[x] = false;
            par[x] = x + 1;
            addSum(x, -(ll)a[x]);
            addCnt(x, -1);
            rebuild((x - 1) / B);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            int x = kth(k);
            ll ans = 0;
            while (true) {
                ans += cntv[x];
                int e = lst[x];
                ll t = (ll)e + a[e];
                if (t > n) break;
                int y = findNext((int)t);
                if (y > n) break;
                x = y;
            }
            out += to_string(ans);
            out += '\n';
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            ll ans = getSum(r) - getSum(l - 1);
            out += to_string(ans);
            out += '\n';
        }
    }
    fputs(out.c_str(), stdout);
    return 0;
}