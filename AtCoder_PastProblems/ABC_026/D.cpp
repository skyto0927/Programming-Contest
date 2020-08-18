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
    double A,B,C; cin >> A >> B >> C;

    double ng = 100/A - 1/C;
    double ok = 100/A + 1/C;

    REP(i,1000){
        double mid = (ok+ng)/2;

        double f = A*mid + B*sin(C*mid*M_PI);
        if(f > 100){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
        //cout << ng << " " << ok << endl;
    }

    cout << fixed << setprecision(10) << ok << endl;

    return 0;
}