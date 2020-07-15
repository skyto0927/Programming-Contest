#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18

template<typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2){
    vector<T> vals;
    int N = (int)C1.size();
    REP(i,N){
        vals.push_back(C1[i]);
        vals.push_back(C1[i]+1);

        vals.push_back(C2[i]);
        vals.push_back(C2[i]+1);
    }

    sort(ALL(vals));
    vals.erase(unique(ALL(vals)), vals.end());

    REP(i,N){
        C1[i] = lower_bound(ALL(vals), C1[i]) - vals.begin();
        C2[i] = lower_bound(ALL(vals), C2[i]) - vals.begin();
    }

    return vals;
}

int main() {
    int N,K; cin >> N >> K;

    vector<ll> X1(N), Y1(N), X2(N), Y2(N), D1(N), D2(N);
    REP(i,N){
        cin >> X1[i] >> Y1[i] >> D1[i] >> X2[i] >> Y2[i] >> D2[i];
    }

    vector<ll> X = compress(X1,X2);
    vector<ll> Y = compress(Y1,Y2);
    vector<ll> D = compress(D1,D2);

    int x = X.size(), y = Y.size(), z = D.size();

    vector<vector<vector<int>>> G(x, vector<vector<int>>(y, vector<int>(z,0)));

    REP(i,N){
        vector<ll> xx{X1[i], X2[i]};
        vector<ll> yy{Y1[i], Y2[i]};
        vector<ll> dd{D1[i], D2[i]};
        REP(a,2){
            REP(b,2){
                REP(c,2){
                    if((a+b+c)%2 == 0) G[xx[a]][yy[b]][dd[c]] ++;
                    else G[xx[a]][yy[b]][dd[c]] --;
                }
            }
        }
    }

    REP(a,x){
        REP(b,y){
            REP(c,z-1){
                G[a][b][c+1] += G[a][b][c];
            }
        }
    }
    REP(a,x){
        REP(b,y-1){
            REP(c,z){
                G[a][b+1][c] += G[a][b][c];
            }
        }
    }
    REP(a,x-1){
        REP(b,y){
            REP(c,z){
                G[a+1][b][c] += G[a][b][c];
            }
        }
    }

    ll ans = 0;

    REP(a,x-1){
        REP(b,y-1){
            REP(c,z-1){
                if(G[a][b][c]>=K){
                    ans += (X[a+1]-X[a]) * (Y[b+1]-Y[b]) * (D[c+1]-D[c]);
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}