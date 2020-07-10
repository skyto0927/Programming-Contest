#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<int> A(M,0);
    REP(k,N){
        int K; cin >> K;
        REP(i,K){
            int a; cin >> a; a--;
            A[a]++;
        }
    }

    int ans = 0;
    REP(i,M){  
        if(A[i] == N) ans++;
    }
    cout << ans << endl;
    return 0;
}