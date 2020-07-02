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
    vector<int> H(N);
    REP(i,N){
        cin >> H[i];
    }

    vector<vector<int>> G(N);

    vector<bool> seen(N,false);

    REP(i,M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    REP(i,N){
        bool ok = true;
        seen[i] = true;
        for(auto next: G[i]){
            if(H[i] <= H[next]){
                ok = false;
            }
        }
        if(ok){
            ans++;
        }
    }

    REP(i,N){
        if(!seen[i]){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}