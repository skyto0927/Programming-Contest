#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

struct starry_sky_tree {
    int size;
    vector<ll> data;
    vector<ll> lazy;
    vector<ll> width;

    starry_sky_tree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        data.resize(size*2, 0);
        lazy.resize(size*2, 0);
        width.resize(size*2, 1);
        for (int i = size-2; i >= 0; i--) {
            width[i] = width[i*2+1] + width[i*2+2];
        }
    }

    void lazy_propagate(int p) {
        data[p] += lazy[p];
        if (p < size-1) {
            lazy[p*2+1] += lazy[p];
            lazy[p*2+2] += lazy[p];
        }
        lazy[p] = 0;
    }

    void add(int wishl, int wishr, int x) {
        add(wishl, wishr, 0, size, 0, x);
    }
    void add(int wishl, int wishr, int watchl, int watchr, int k, int x) {
        if (wishr <= watchl || watchr <= wishl) {
            lazy_propagate(k);
            return;
        }
        if (wishl <= watchl && watchr <= wishr) {
            lazy[k] += x;
            lazy_propagate(k);
            return;
        }

        int mid = (watchl + watchr) / 2;
        lazy_propagate(k);
        add(wishl, wishr, watchl, mid, k*2+1, x);
        add(wishl, wishr, mid, watchr, k*2+2, x);
        data[k] = max(data[k*2+1], data[k*2+2]);
    }

    int getmax(int wishl, int wishr) {
        return getmax(wishl, wishr, 0, size, 0);
    }
    int getmax(int wishl, int wishr, int watchl, int watchr, int k) {
        if (wishr <= watchl || watchr <= wishl) return 0;
        if (wishl <= watchl && watchr <= wishr) {
            lazy_propagate(k);
            return data[k];
        }

        int mid = (watchl + watchr) / 2;
        int L = getmax(wishl, wishr, watchl, mid, k*2+1);
        int R = getmax(wishl, wishr, mid, watchr, k*2+2);
        return max(L, R);
    }
};

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return e;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }

    int find_rightest(int a, int b, T x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    int find_leftest(int a, int b, T x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    int find_rightest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a - 1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    int find_leftest_sub(int a, int b, T x, int k, int l, int r) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};

int main() {
    int H,W; cin >> H >> W;
    vector<int> A(H), B(H);
    REP(i,N){
        cin >> A[i] >> B[i];
        A[i]--;
    }

    starry_sky_tree sst(W);

    int l = 0;
    int r = 0;
    REP(i,H){
        sst.add(0,A[i],1);
        sst.add(A[i],B[i],INF);
        sst.add(B[i],W,1);

    }

    return 0;
}