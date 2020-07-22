#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<vector<int>> F(N, vector<int>(10,0));
    vector<vector<int>> P(N, vector<int>(11,0));

    REP(i,N){
        REP(j,10){
            cin >> F[i][j];
        }
    }

    REP(i,N){
        REP(j,11){
            cin >> P[i][j];
        }
    }

    int ans = -INF;
    FOR(bit,1,1<<10){
        vector<int> S;
        REP(i,10){
            if(bit & (1<<i)){
                S.push_back(i);
            }
        }

        int num = 0;

        REP(i,N){
            int cnt = 0;
            for(auto s: S){
                if(F[i][s] == 1) cnt++;
            }
            num += P[i][cnt];
        }
        ans = max(ans,num);
    }
    cout << ans << endl;
    return 0;
}