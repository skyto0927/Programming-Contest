#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<typename T> vector<T> compress(vector<T> &C1){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
    }

    return vals;
}

int main() {
    int N; cin >> N;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    vector<int> X = compress(a);
    REP(i,N) cout << a[i] << endl;
    return 0;
}