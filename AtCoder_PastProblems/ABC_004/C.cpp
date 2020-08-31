#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    N %= 30;
    vector<int> A(6);
    REP(i,6) A[i] = i+1;

    REP(i,N){
        swap(A[i%5], A[i%5 + 1]);
    }
    REP(i,6){
        cout << A[i];
    }
    cout << endl;
    return 0;
}