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
    vector<int> a(N);
    REP(i,N) a[i] = i;

    vector<double> X(N), Y(N);
    REP(i,N){
        cin >> X[i] >> Y[i];
    }

    double ans = 0.0;
    double bunbo = 1;
    REP(i,N){
        bunbo *= i+1;
    }
    do{
        double sum = 0.0;
        REP(i,N-1){
            sum += sqrt((X[a[i]]-X[a[i+1]])*(X[a[i]]-X[a[i+1]]) + (Y[a[i]]-Y[a[i+1]])*(Y[a[i]]-Y[a[i+1]]));
        }

        ans += sum;
    }while(next_permutation(ALL(a)));

    cout << fixed << setprecision(10) << ans/bunbo << endl;
    return 0;
}