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

    int N; cin >> N;
    vector<vector<int>> A(N,vector<int>(N,-1));
    REP(i,N){
        int a; cin >> a;
        REP(j,a){
            int x,y; cin >> x >> y;
            x--;
            A[i][x] = y;
        }
    }

    int ans = 0;

    REP(bit, (1<<N)){
        bool ok = true;
        REP(i,N){
            if(!((bit>>i)&1)) continue;//iが不親切ならスルー
            REP(j,N){
                if(A[i][j]==-1) continue;
                if(A[i][j] != ((bit>>j)&1) ){//矛盾があればNG
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            ans = max(ans,__builtin_popcount(bit));
        }

    }
    cout << ans << endl;
    return 0;
}