#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

struct Cake{
    ll x,y,z;
};

int main() {
    int N,M; cin >> N >> M;

    vector<Cake> cakes(N);
    REP(i,N) cin >> cakes[i].x >> cakes[i].y >> cakes[i].z;

    

    ll ans = 0;
    
    REP(x,2){
        REP(y,2){
            REP(z,2){
                vector<ll> sum(N,0);
                REP(i,N){
                    sum[i] += x? cakes[i].x: -cakes[i].x;
                    sum[i] += y? cakes[i].y: -cakes[i].y;
                    sum[i] += z? cakes[i].z: -cakes[i].z;
                }
                sort(ALL(sum), greater<ll>());
                ll s = 0;
                REP(j,M) s += sum[j];
                ans = max(ans, s);
            }
        }
    }

    cout << ans << endl;


    return 0;
}