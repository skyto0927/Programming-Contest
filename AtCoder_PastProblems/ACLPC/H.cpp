#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,D; cin >> N >> D;
    vector<int> X(N), Y(N);
    REP(i,N) cin >> X[i] >> Y[i];

    two_sat ts(N);

    REP(i,N-1){
        FOR(j,i+1,N){
            if(abs(X[i]-X[j]) < D) ts.add_clause(i,false, j,false);//x[i]^x[j]「以外」なのでこうなる
            if(abs(X[i]-Y[j]) < D) ts.add_clause(i,false, j,true);
            if(abs(Y[i]-X[j]) < D) ts.add_clause(i,true, j,false);
            if(abs(Y[i]-Y[j]) < D) ts.add_clause(i,true, j,true);
        }
    }

    if(!ts.satisfiable()){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    auto ans = ts.answer();
    REP(i,N){
        cout << (ans[i]?X[i]:Y[i]) << endl;
    }

    return 0;
}