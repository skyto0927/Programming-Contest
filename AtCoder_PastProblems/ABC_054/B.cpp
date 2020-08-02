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
    int N,M; cin >> N >> M;
    vector<string> A(N), B(M);
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];
    REP(i,N-M+1){
        REP(j,N-M+1){
            bool ok = true;
            REP(k,M){
                REP(l,M){
                    if(B[k][l] != A[k+i][l+j]) ok = false;
                }
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}