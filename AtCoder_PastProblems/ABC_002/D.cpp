#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> p(N, vector<int>(N,0));
    REP(i,M){
        int x,y; cin >> x >> y;
        x--;
        y--;
        p[x][y] = 1;
        p[y][x] = 1;
    }

    REP(i,N){
        p[i][i] = 1;
    }

    int ans = 0;
    FOR(bit,1,(1<<N)){
        vector<int> S;
        REP(i,N){
            if(bit & (1<<i)){
                S.push_back(i);
            }
        }

        int s = S.size();

        bool ok = true;
        REP(i,s){
            REP(j,s){
                if(p[S[i]][S[j]] == 0) ok = false;
            }
        }
        if(ok) ans = max(ans,s);
    }

    cout << ans << endl;
    return 0;
}