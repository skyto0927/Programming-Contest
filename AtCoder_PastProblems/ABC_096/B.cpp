#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    vector<int> A(3); cin >> A[0] >> A[1] >> A[2];
    int K; cin >> K;

    sort(ALL(A));

    REP(i,K) A[2] *= 2;
    cout << A[0] + A[1] + A[2] << endl;
    return 0;
}