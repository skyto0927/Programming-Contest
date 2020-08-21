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
    int N; cin >> N;
    int a,b; cin >> a >> b;
    a--;
    b--;
    int K; cin >> K;
    vector<int> P(N,0);
    P[a]++;
    P[b]++;
    REP(i,K){
        int p; cin >> p;
        p--;
        P[p]++;
    }

    REP(i,N){
        if(P[i] > 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}