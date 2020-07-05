#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i,N){
        cin >> A[i];
    }

    if(N==2){
        cout << max(A[0], A[1]) << endl;
    }else{
        vector<int> g(N);
        vector<int> gr(N);
        g[1] = A[0];
        gr[N-2] = A[N-1];
        FOR(j,1,N-1){
            g[j+1] = __gcd(g[j], A[j]);
            gr[N-2-j] = __gcd(gr[N-1-j], A[N-1-j]);
        }
        g[0] = gr[0];
        gr[N-1] = g[N-1];

        int ans = 0;
        REP(i,N){
            ans = max(ans, __gcd(g[i], gr[i]));
        }
        cout << ans << endl;
    }


    return 0;
}