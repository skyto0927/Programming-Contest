#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


struct TV{
    int s,t,c;
    bool operator<(const TV &o) const{
        return t < o.t;
    }
};

int main() {
    int N,C; cin >> N >> C;

    vector<vector<int>> tv(C+1,vector<int>(100100,0));

    REP(i,N){
        int s,t,c; cin >> s >> t >> c;
        tv[c][s] += 1;
        tv[c][t+1] -= 1;
    }

    REP(i,C+1){
        REP(j,100010){
            tv[i][j+1] += tv[i][j];
        }
    }

    int ans = 0;
    REP(j,100010){
        int cnt = 0;
        REP(i,C+1){
            if(tv[i][j]>0)cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}