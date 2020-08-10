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
    vector<string> S(N);
    REP(i,N) cin >> S[i];
    REP(i,N){
        REP(j,N){
            cout << S[N-j-1][i];
        }
        cout << endl;
    }
    return 0;
}