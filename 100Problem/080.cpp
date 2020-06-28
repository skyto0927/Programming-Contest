#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int H,W,K; ll V; cin >> H >> W >> K >> V;
    vector<vector<ll>> A(H+1, vector<ll>(W+1,0));

    FOR(i,1,H+1){
        FOR(j,1,W+1){
            cin >> A[i][j];
        }
    }

    REP(i,H+1){
        REP(j,W){
            A[i][j+1] += A[i][j];
        }
    }
    REP(i,H){
        REP(j,W+1){
            A[i+1][j] += A[i][j];
        }
    }

    //[a,b] [c,d]の組を全探索

    ll ans = 0;

    FOR(a,1,H+1){
        FOR(b,1,W+1){
            FOR(c,a,H+1){
                FOR(d,b,W+1){
                    ll S = (d-b+1)*(c-a+1);
                    ll value = A[c][d] - A[c][b-1] - A[a-1][d] + A[a-1][b-1] + S*K;
                    if (value <= V){
                        ans = max(ans, S);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}