#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18


int main() {
    int N,M; cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i,M){
        int a,b; cin >> a >> b;
        G[a-1].push_back(b-1);
    }
    REP(i,N){
        sort(ALL(G[i]));
    }
    int l = 0, r = N-1;
    int ans = 0;
    REP(i,N-1){
        l = i;
        if(G[i].size() > 0) r = min(r, G[i][0]);

        //cout << l << ", " << r << endl;
        if(r-l == 1){
            ans++;
            r = N;
        }
    }

    cout << ans << endl;

    return 0;
}