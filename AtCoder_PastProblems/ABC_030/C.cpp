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
    int X,Y; cin >> X >> Y;
    vector<int> A(N), B(M);
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];
    int go_itr = 0;
    int back_itr = 0;
    int ans = 0;
    while(go_itr < N){
        back_itr = lower_bound(ALL(B), A[go_itr]+X) - B.begin();

        if(back_itr == M) break;
        go_itr = lower_bound(ALL(A), B[back_itr]+Y) - A.begin();
        ans ++;
    }
    cout << ans << endl;
    return 0;
}