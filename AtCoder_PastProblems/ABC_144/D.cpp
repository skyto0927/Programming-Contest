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
    int a,b,x; cin >> a >> b >> x;

    if(2*x>=a*a*b){
        cout << fixed << setprecision(10) << 90.0 - atan(a*a*a*1.0/(2*a*a*b - 2*x))*180/M_PI << endl;
    }else{
        cout << fixed << setprecision(10) << 90.0 - atan(2.0*x/(a*b*b))*180/M_PI << endl;
    }
    return 0;
}