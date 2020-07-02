#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M,X; cin >>N>>M>>X;
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    REP(i,N){
        cin >> C[i];
        REP(j,M){
            cin >> A[i][j];
        }
    }
    int ans = INF;
    REP(bit,1<<N){
        int cost = 0;
        vector<int> skills(M,0);
        REP(n,N){
            if(bit & (1<<n)){
                cost += C[n];
                REP(i,M){
                    skills[i] += A[n][i];
                }
            }
        }
        bool archived = true;
        REP(i,M){
            if (skills[i] < X){
                archived = false;
            }
        }
        if(archived){
            ans = min(ans, cost);
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}