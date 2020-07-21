#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,C,X; cin >> A >> B >> C >> X;
    int ans = 0;
    REP(i,A+1){
        REP(j,B+1){
            REP(k,C+1){
                if(500*i + 100*j + 50*k == X) ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}