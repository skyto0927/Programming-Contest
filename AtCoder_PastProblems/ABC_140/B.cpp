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
    vector<int> A(N),B(N),C(N-1);
    int ans = 0;
    REP(i,N) cin >> A[i];
    REP(i,N){
        cin >> B[i];
        ans += B[i];
    }
    REP(i,N-1) cin >> C[i];

    
    REP(i,N-1){
        if(A[i+1]-A[i] == 1){
            ans += C[A[i]-1];
        }
    }

    cout << ans << endl;
    return 0;
}