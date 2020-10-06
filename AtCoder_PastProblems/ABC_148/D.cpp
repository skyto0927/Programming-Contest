#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    int cur = 1;
    REP(i,N){
        if(A[i]==cur){
            cur++;
        }
    }
    cout << (cur==1?-1:N - cur + 1) << endl;
    return 0;
}