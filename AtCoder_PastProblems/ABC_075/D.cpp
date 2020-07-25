#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

template<typename T> vector<T> compress(vector<T> &C1){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);

        //vals.push_back(C2[i]);
        //vals.push_back(C2[i]+1);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
        //C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    }

    return vals;
}

int main() {
    int N,K; cin >> N >> K;
    vector<ll> X(N), Y(N);
    REP(i,N){
        cin >> X[i] >> Y[i];
    }
    vector<ll> CX = compress(X);
    vector<ll> CY = compress(Y);

    ll ans = LLONG_MAX;
    vector<vector<int>> G(N+1,vector<int>(N+1,0));
    REP(i,N){
        G[X[i]+1][Y[i]+1] ++;
    }

    REP(i,N){
        REP(j,N+1){
            G[i+1][j] += G[i][j];
        }
    }
    REP(i,N+1){
        REP(j,N){
            G[i][j+1] += G[i][j];
        }
    }

    // REP(i,N+1){
    //     REP(j,N+1){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    REP(x1,N){
        REP(y1,N){
            FOR(x2,x1+1,N+1){
                FOR(y2,y1+1,N+1){
                    //cout << "(" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")";
                    //cout << ": " << G[x2][y2] + G[x1][y1] - G[x1][y2] - G[x2][y1] << endl;
                    if(G[x2][y2] + G[x1][y1] - G[x1][y2] - G[x2][y1] >= K){
                        ll num = (CX[x2-1]-CX[x1]) * (CY[y2-1]-CY[y1]);
                        ans = min(ans,num);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}