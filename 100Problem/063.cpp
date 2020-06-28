#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e12
typedef long long ll;

int N;
vector<vector<bool>> A(300, vector<bool>(300,true));
vector<vector<ll>> dp(300, vector<ll>(300,INF));

int main() {
    cin >> N;

    REP(i,N){
        REP(j,N){
            cin >> dp[i][j];
        }
    }

    REP(i,N){
        REP(j,N){
            REP(k,N){
                if (j==k || k==i || i==j) continue;
                if (dp[j][k] > dp[j][i] + dp[i][k]){
                    cout << -1 << endl;
                    return 0;
                }else if (dp[j][k] == dp[j][i] + dp[i][k]){
                    A[j][k] = false;
                }
            }
        }
    }

    ll ans = 0;

     REP(i,N){
        REP(j,N){
            if (A[i][j]) ans += dp[i][j];
        }
    }

    cout << ans/2 << endl;

    return 0;
}

/*
別ルートの値を差分として集める方針だと、
1→2→3も1→4→3も1→3とおなじコストの時1→3を2回カウントしてしまうので、
真偽値表を別途用意してやると重複がない
*/