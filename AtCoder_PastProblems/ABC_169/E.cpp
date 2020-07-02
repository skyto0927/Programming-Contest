#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    REP(i,N){
        cin >> A[i] >> B[i];
    }

    sort(ALL(A));
    sort(ALL(B));
    if(N%2 == 1){
        int A_median = A[N/2];
        int B_median = B[N/2];
        cout << B_median - A_median + 1 << endl;
    }else{
        int A_median = (A[N/2-1] + A[N/2]);
        int B_median = (B[N/2-1] + B[N/2]);
        cout << B_median - A_median + 1 << endl;
    }
    return 0;
}