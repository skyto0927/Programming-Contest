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
    vector<pair<int,int>> G(M);
    REP(i,M){
        int a,b; cin >> a >> b;
        G[i] = {b,a};
    }
    
    sort(ALL(G));
    

    int r = -1;//右端
    int ans = 0;
    REP(i,M){
        if(r<G[i].second || G[i].first<r){
            r = G[i].first-1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}