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
    int N,T; cin >> N >> T;
    vector<int> G(1e7,0);
    REP(i,N){
        int a; cin >> a;
        G[a]++;
        G[a+T]--;
    }
    int ans = 0;
    REP(i,1e7-1){
        G[i+1] += G[i];
        if(G[i]>0) ans++;
    }
    cout << ans << endl;
    return 0;
}