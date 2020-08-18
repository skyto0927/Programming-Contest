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
    vector<int> L(N);
    REP(i,N) cin >> L[i];
    sort(ALL(L));
    ll ans = 0;
    REP(i,N-2){
        FOR(j,i+1,N-1){
            FOR(k,j+1,N){
                if(L[i]!=L[j] && L[j]!=L[k] && L[k]!=L[i]){
                    if(L[i]+L[j] > L[k]) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}