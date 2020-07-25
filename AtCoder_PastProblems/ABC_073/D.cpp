#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

template<class T> void warshall_floyd(vector<T>& G){
    int N = G.size();
    REP(k,N){
        REP(i,N){
            REP(j,N){
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}


int main() {
    int N,M,R; cin >> N >> M >> R;
    vector<int> r(R);
    REP(i,R){
        cin >> r[i];
        r[i]--;
    }

    sort(ALL(r));
    vector<vector<int>>  G(N,vector<int>(N,1e7));
    REP(i,M){
        int a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    REP(i,N){
        G[i][i] = 0;
    }
    warshall_floyd(G);

    int ans = INF;
    do{
        int num = 0;
        REP(i,R-1){
            //cout << r[i] << ", " << r[i+1] << endl;
            num += G[r[i]][r[i+1]];
        }
        ans = min(ans,num);
    }while(next_permutation(ALL(r)));
    cout<< ans << endl;


    return 0;
}