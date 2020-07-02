#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    double A,B,H,M; cin>>A>>B>>H>>M;
    double theta = abs(30*H+-5.5*M);
    if (theta > 180){
        theta = 360 - theta;
    }
    double ans = sqrt(A*A + B*B - 2*A*B*cos(theta*M_PI/180));

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}