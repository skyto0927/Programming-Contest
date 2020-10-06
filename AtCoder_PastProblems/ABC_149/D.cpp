#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,K; cin >> N >> K;
    vector<int> point(3); cin >> point[0] >> point[1] >>point[2];
    string T; cin >> T;

    vector<vector<int>> dp(N, vector<int>(3,0));

    map<char, int> rsp;
    rsp['r'] = 0;
    rsp['s'] = 1;
    rsp['p'] = 2;

    REP(i,K){//開始点をk箇所それぞれで
        
        dp[i][(rsp[T[i]]+2)%3] = point[(rsp[T[i]]+2)%3];
        int itr = i+K;

        while(itr < N){
            dp[itr][(rsp[T[itr]]+2)%3] = max(dp[itr-K][(rsp[T[itr]])%3], dp[itr-K][(rsp[T[itr]]+1)%3]) + point[(rsp[T[itr]]+2)%3];//勝つ場合
            dp[itr][(rsp[T[itr]])%3] = max(dp[itr-K][(rsp[T[itr]]+1)%3], dp[itr-K][(rsp[T[itr]]+2)%3]);//あいこ
            dp[itr][(rsp[T[itr]]+1)%3] = max(dp[itr-K][(rsp[T[itr]])%3], dp[itr-K][(rsp[T[itr]]+2)%3]);//負け
            itr += K;
        }
    }

    ll ans = 0;
    for(int i = N-1; i>=N-K; i--){
        ans += max({dp[i][0], dp[i][1], dp[i][2]});
    }
    cout << ans << endl;

    // REP(i,3){
    //     REP(j,N){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}