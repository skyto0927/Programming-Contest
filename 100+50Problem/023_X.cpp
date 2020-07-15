#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    REP(i, N) cin >> P[i];
    vector<int> P2;

    REP(i,N) P2.push_back(P[i]);

    REP(i,N){
        REP(j,N){
            P2.push_back(P[i]+P[j]);
        }
    }

    sort(ALL(P2));

    int ans = 0;
    REP(i,(int)P2.size()){
        if (P2[i] < M){
            ans = max(ans, P2[i]);
            int M2 = M - P2[i];
            auto itr = upper_bound(ALL(P2), M2);
            itr--;
            if(itr >= P2.begin() && P2[i]+*itr<=M){
                ans = max(ans, P2[i]+*itr);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
