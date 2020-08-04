#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> d{-1,0,1};

int main() {
    ll H,W,N; cin >> H >> W >> N;
    map<pair<ll,ll>, int> G;
    REP(i,N){
        ll x,y; cin >> x >> y;
        x--;
        y--;
        REP(j,3){
            REP(k,3){
                G[{x+d[j],y+d[k]}] ++;
            }
        }
    }
    vector<ll> ans(10);
    ans[0] = (W-2)*(H-2);
    for(auto g: G){
        int a,b;
        a = g.first.first;
        b = g.first.second;
        if(1<=a && a<=H-2 && 1<=b && b<=W-2){
            ans[g.second]++;
            ans[0]--;
        }
    }
    REP(i,10){
        cout << ans[i] << endl;
    }
    return 0;
}