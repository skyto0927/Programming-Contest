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
    int N,M; cin >> N >> M;
    vector<int> a(N+1,0);
    REP(i,M){
        int l,r; cin >> l >> r;
        l--;
        r--;
        a[l]++;
        a[r+1]--;
    }

    int ans = 0;
    REP(i,N){
        a[i+1] += a[i];
    }
    REP(i,N){
        if(a[i]==M) ans++;
    }
    cout << ans << endl;
    return 0;
}