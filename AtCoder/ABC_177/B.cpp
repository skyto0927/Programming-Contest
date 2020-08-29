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
    string S,T; cin >> S >> T;

    int s = S.size();
    int t = T.size();

    int ans = INF;
    REP(i,s-t+1){
        int cnt = 0;
        REP(j,t){
            if(S[i+j] != T[j]) cnt++;
        }

        ans = min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}