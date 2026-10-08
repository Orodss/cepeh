#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;

u64 pw(u64 b, u64 e, u64 m) {
    u64 r = 1; b %= m;
    while (e) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL}) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    u64 d = n - 1; int s = 0;
    while ((d & 1) == 0) d >>= 1, s++;
    for (u64 a : {2ULL, 3ULL, 5ULL, 7ULL}) {
        u64 x = pw(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int i = 1; i < s; i++) {
            x = x * x % n;
            if (x == n - 1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}

u64 rho(u64 n) {
    for (u64 c = 1;; c++) {
        auto f = [&](u64 x) { return (x * x + c) % n; };
        u64 x = 2, y = 2, d = 1;
        while (d == 1) {
            // batch of 64 steps
            u64 sx = x, sy = y, prod = 1;
            for (int i = 0; i < 64; i++) {
                x = f(x);
                y = f(f(y));
                u64 diff = x > y ? x - y : y - x;
                prod = prod * (diff % n) % n;
            }
            d = __gcd(prod, n);
            if (d == n) {
                // redo this batch step by step
                x = sx; y = sy; d = 1;
                for (int i = 0; i < 64 && d == 1; i++) {
                    x = f(x);
                    y = f(f(y));
                    u64 diff = x > y ? x - y : y - x;
                    d = __gcd(diff, n);
                }
                break;
            }
        }
        if (d != 1 && d != n) return d;
    }
}

void factorBig(u64 n, vector<u64> &out) {
    if (n == 1) return;
    if (isPrime(n)) { out.push_back(n); return; }
    u64 r = (u64)sqrtl((long double)n);
    while (r * r > n) r--;
    while ((r + 1) * (r + 1) <= n) r++;
    if (r * r == n) { out.push_back(r); return; }
    u64 d = rho(n);
    factorBig(d, out);
    factorBig(n / d, out);
}

int par[200005];
int find(int x) {
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) par[a] = b;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    vector<int> small;
    {
        vector<bool> comp(1001, false);
        for (int i = 2; i <= 1000; i++) {
            if (!comp[i]) {
                small.push_back(i);
                for (int j = i * i; j <= 1000; j += i) comp[j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) par[i] = i;

    vector<pair<u64, int>> pr;  // (prime, index)
    pr.reserve(n * 4);
    for (int i = 1; i <= n; i++) {
        u64 x = a[i];
        for (int p : small) {
            if ((u64)p * p > x) break;
            if (x % p == 0) {
                pr.push_back({(u64)p, i});
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) {
            vector<u64> f;
            factorBig(x, f);
            for (u64 p : f) pr.push_back({p, i});
        }
    }

    sort(pr.begin(), pr.end());
    for (size_t i = 1; i < pr.size(); i++) {
        if (pr[i].first == pr[i - 1].first) unite(pr[i].second, pr[i - 1].second);
    }

    int root = find(1);
    vector<int> L;
    for (int i = 1; i <= n; i++)
        if (find(i) == root) L.push_back(i);

    if ((int)L.size() == n) {
        puts("NO");
        return 0;
    }

    printf("YES\n%d\n", (int)L.size());
    string out;
    for (size_t i = 0; i < L.size(); i++) {
        if (i) out += ' ';
        out += to_string(L[i]);
    }
    puts(out.c_str());
    return 0;
}