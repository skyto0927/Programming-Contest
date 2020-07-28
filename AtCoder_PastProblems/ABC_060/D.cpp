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
    ll N,W; cin >> N >> W;
    vector<vector<ll>> V(4);
    ll w1; 
    REP(i,N){
        ll w,v; cin >> w >> v;
        if(i==0){
            w1 = w;
            V[0].push_back(v);
        }else{
            V[w-w1].push_back(v);
        }
    }
    REP(i,4){
        if(V[i].size()!=0){
            sort(ALL(V[i]), greater<ll>());
            REP(j,V[i].size()-1){
                V[i][j+1] += V[i][j];
            }
        }
        V[i].push_back(0);
        sort(ALL(V[i]));
    }
    ll ans = 0;
    REP(a,V[0].size()){
        REP(b,V[1].size()){
            REP(c,V[2].size()){
                REP(d,V[3].size()){
                    if(a*w1 + b*(w1+1) + c*(w1+2) + d*(w1+3) > W) continue;
                    ans = max(ans, V[0][a]+V[1][b]+V[2][c]+V[3][d]);
                }
            }
        }
    }

    cout << ans << endl;
    
    

    return 0;
}