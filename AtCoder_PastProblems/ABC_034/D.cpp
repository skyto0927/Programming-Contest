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
    int N,K; cin >> N >> K;
    vector<double> w(N),p(N);
    REP(i,N) cin >> w[i] >> p[i];
    double ng = 0.0;
    double ok = 100.0;
    REP(n,500){
        double mid = (ok+ng)/2.0;
        vector<double> S(N);
        REP(i,N){
            S[i] = w[i] * (p[i]-mid);
        }
        sort(ALL(S), greater<double>());
        double sum = 0;
        REP(i,K) sum += S[i];
        if(sum >= 0.0){//ここに条件をかく
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout << fixed << setprecision(9) << ok << endl;

    return 0;
}