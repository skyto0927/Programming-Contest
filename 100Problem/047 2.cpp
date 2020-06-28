#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N;
int mod_N(int x){//ループ用にmodNを準備
    int n = x;
    if(x<0) n+=N;
    return n%=N;
}

int main() {
    cin >> N;

    vector<ll> A(N);
    REP(i,N) cin >> A[i];

    vector<vector<ll>> dp(N, vector<ll>(N,LLONG_MIN));
    REP(i,N) dp[i][i] = A[i];

    FOR(w,1,N+1){
        REP(l,N){//[l,r]の気持ちでl-1とr+1を比較しないとまずい
            int r = mod_N(l+w-1);

            if (w%2 == 1){//IOI
                if(A[mod_N(l-1)]>A[mod_N(r+1)]){
                    dp[mod_N(l-1)][r] = max(dp[mod_N(l-1)][r], dp[l][r]);
                }else{
                    dp[l][mod_N(r+1)] = max(dp[l][mod_N(r+1)], dp[l][r]);
                }
            }else{//JOI
                dp[mod_N(l-1)][r] = max(dp[mod_N(l-1)][r], dp[l][r] + A[mod_N(l-1)]);
                dp[l][mod_N(r+1)] = max(dp[l][mod_N(r+1)], dp[l][r] + A[mod_N(r+1)]);
            }
        }
    }
    ll ans = 0;
    REP(i,N){//mod_N(r-l) = N-1となるところの最大値
        ans = max(ans, dp[i][mod_N(i-1)]);
    }
    cout << ans << endl;
    return 0;
}