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
    vector<string> S(N);
    REP(i,N) cin >> S[i];

    int M; cin >> M;
    vector<string> T(M);
    REP(i,M) cin >> T[i];

    int ans = 0;
    REP(i,N){
        int cnt = 0;
        REP(j,N){
            if(S[i] == S[j]) cnt++;
        }
        REP(j,M){
            if(S[i] == T[j]) cnt--;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}