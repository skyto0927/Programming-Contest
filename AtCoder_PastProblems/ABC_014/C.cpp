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
    int n; cin >> n;
    vector<int> A(1e6+2,0);
     REP(i,n){
        int a,b; cin >> a >> b;
        A[a]++;
        A[b+1]--;
    }
    int ans = 0;
    REP(i,1e6+1){
        A[i+1] += A[i];
        ans = max(A[i],ans);
    }
    cout << ans << endl;
    return 0;
}