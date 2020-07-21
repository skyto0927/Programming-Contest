#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int Q; cin >> Q;
    REP(i,Q){
        ll A,B; cin >> A >> B;
        if(A==B){
            cout << 2*A-2 << endl;
        }else{
            ll max_score = A*B - 1;
            ll ng = -1;
            ll ok = 2e9;
            while(abs(ok-ng)>1){
                ll mid = (ok+ng)/2;
                if(mid*mid > max_score){//ここに条件をかく
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            if(ng*(ng+1) <= max_score) cout << 2*ng - 1 << endl;
            else cout << 2*ng - 2 << endl;
        }


    }
    return 0;
}