#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,C,D,E,F; cin >> A >> B >> C >> D >> E >> F;

    int ans_water = 0;
    int ans_sugar = 0;
    double ans = 0.0;
    REP(a,16){
        REP(b,16){
            REP(c,800){
                REP(d,800){
                    int f = 100*A*a + 100*B*b + C*c + D*d;
                    int e = E*(A*a + B*b) - C*c - D*d;
                    if(e>=0 && f<=F){
                        if(f*ans_sugar <= (C*c+D*d)*ans_water){
                            ans_water = f;
                            ans_sugar = C*c + D*d;
                        }
                    }
                }
            }
        }
    }
    cout << ans_water << " " << ans_sugar << endl;
    return 0;
}