#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector <int> A(N);
    vector <int> B(N);
    vector <int> C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));
    
    ll sum = 0;
    for(int i=0; i<N; i++){
        auto a_itr = lower_bound(ALL(A), B[i]);
        auto c_itr = upper_bound(ALL(C), B[i]);
        sum += (a_itr - A.begin()) * (C.end() - c_itr);
    }

    cout << sum << endl;
    return 0;
}
