#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M;
    cin >> N >> M;

    vector<vector<int>> switches(M,vector<int>(N,0));
    REP(i,M){
        int k;
        cin >> k;
        REP(j,k){
            int s;
            cin >> s;
            switches[i][s-1] = 1;
        }
    }
    vector<int> p(M);
    REP(i,M){
        cin >> p[i];
    }

    int ans = 0;
    REP(bit, 1<<N){
        vector<int> B;
        bool ok = true;
        REP(i,N){
            if(bit & (1<<i)){
                B.push_back(i);
            }
        }
        
        REP(i,M){
            int count = 0;
            for(int j: B){
                count += switches[i][j];
            }
            if(count%2 != p[i]){
                ok = false;
            }
        }
        if(ok){
            ans ++;
        }
    }

    cout << ans << endl;


    return 0;
}