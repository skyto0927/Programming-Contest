#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> AB(K);
    REP(i,K){
        int A,B;
        cin >> A >> B;
        AB[i] = make_pair(A-1,B-1);
    }
    sort(ALL(AB));

    vector<vector<ll>> dp(6,vector<ll>(N+1,0));

    int A_index=0;
    if (AB[A_index].first == 0){
        dp[AB[A_index].second*2][1] = 1;
        A_index ++;
    }else{
        dp[0][1] = 1;
        dp[2][1] = 1;
        dp[4][1] = 1;
    }

    FOR(i,1,N){
        REP(k,6){
            dp[k][i]%=10000;
        }
        
        if (i == AB[A_index].first){
            switch(AB[A_index].second){
                case 0:
                    dp[0][i+1] += dp[2][i];
                    dp[0][i+1] += dp[3][i];
                    dp[0][i+1] += dp[4][i];
                    dp[0][i+1] += dp[5][i];

                    dp[1][i+1] += dp[0][i];
                    break;

                case 1:
                    dp[2][i+1] += dp[0][i];
                    dp[2][i+1] += dp[1][i];
                    dp[2][i+1] += dp[4][i];
                    dp[2][i+1] += dp[5][i];

                    dp[3][i+1] += dp[2][i];
                    break;

                case 2:
                    dp[4][i+1] += dp[0][i];
                    dp[4][i+1] += dp[1][i];
                    dp[4][i+1] += dp[2][i];
                    dp[4][i+1] += dp[3][i];

                    dp[5][i+1] += dp[4][i];
                    break;

            }
            A_index ++;
            continue;
        }
        
        REP(j,6){
            switch(j){
                case 0:
                    dp[1][i+1] += dp[j][i];
                    dp[2][i+1] += dp[j][i];
                    dp[4][i+1] += dp[j][i];
                    break;
                
                case 1:
                    dp[2][i+1] += dp[j][i];
                    dp[4][i+1] += dp[j][i];
                    break;

                case 2:
                    dp[0][i+1] += dp[j][i];
                    dp[3][i+1] += dp[j][i];
                    dp[4][i+1] += dp[j][i];
                    break;

                case 3:
                    dp[0][i+1] += dp[j][i];
                    dp[4][i+1] += dp[j][i];
                    break;

                case 4:
                    dp[0][i+1] += dp[j][i];
                    dp[2][i+1] += dp[j][i];
                    dp[5][i+1] += dp[j][i];
                    break;

                case 5:
                    dp[0][i+1] += dp[j][i];
                    dp[2][i+1] += dp[j][i];
                    break;
            }

        }
    }
    ll ans = 0;
    REP(i,6){
        ans += dp[i][N];
        ans %= 10000;
    }



    cout << ans << endl;
    return 0;
}
