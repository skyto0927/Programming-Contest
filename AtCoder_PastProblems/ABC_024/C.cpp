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
    int N,D,K; cin >> N >> D >> K;
    vector<int> L(D),R(D);
    REP(i,D) cin >> L[i] >> R[i];
    vector<int> S(K),T(K);
    REP(i,K) cin >> S[i] >> T[i];
    
    REP(i,K){
        int pos;
        if(S[i] < T[i]){
            pos = S[i];
            REP(j,D){
                if(L[j]<=pos && pos<=R[j]){
                    pos = R[j];
                }

                if(pos >= T[i]){
                    cout << j+1 << endl;
                    break;
                }
            }
        }else{
            pos = S[i];
            REP(j,D){
                if(L[j]<=pos && pos<=R[j]){
                    pos = L[j];
                }

                if(pos <= T[i]){
                    cout << j+1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}