#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<int>> cnt(N+1, vector<int>(4,0));
    REP(i,N){
        if(S[i]=='A') cnt[i+1][0]++;
        if(S[i]=='T') cnt[i+1][1]++;
        if(S[i]=='C') cnt[i+1][2]++;
        if(S[i]=='G') cnt[i+1][3]++;
    }

    REP(i,N){
        REP(j,4){
            cnt[i+1][j] += cnt[i][j];
        }
    }

    ll ans = 0;
    REP(i,N){
        FOR(j,i+1,N+1){
            int a = cnt[j][0]-cnt[i][0];
            int t = cnt[j][1]-cnt[i][1];
            int c = cnt[j][2]-cnt[i][2];
            int g = cnt[j][3]-cnt[i][3];
            if(a==t && c==g) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}