#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
template<typename T>

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


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
    int N; cin >> N;

    vector<ll> X1(N);
    vector<ll> Y1(N);
    vector<ll> X2(N);
    vector<ll> Y2(N);
    REP(i,N){
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }

    vector<ll> X = compress(X1, X2);
    vector<ll> Y = compress(Y1, Y2);

    int w = X.size();
    int h = Y.size();

    vector<vector<int>> G(h, vector<int>(w, 0));

    REP(i,N){
        G[Y1[i]][X1[i]] ++;
        G[Y1[i]][X2[i]] --;
        G[Y2[i]][X1[i]] --;
        G[Y2[i]][X2[i]] ++;
    }

    REP(i,h){
        REP(j,w-1){
            G[i][j+1] += G[i][j];
        }
    }
    REP(i,h-1){
        REP(j,w){
            G[i+1][j] += G[i][j];
        }
    }

    ll ans = 0;
    REP(i,h-1){
        REP(j,w-1){
            if(G[i][j]>0){
                ans += (Y[i+1] - Y[i]) * (X[j+1] - X[j]);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}