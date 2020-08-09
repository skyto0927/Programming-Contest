#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int  MOD = 1e9+7;

struct Edge{
    int h,w,cost;
    bool operator<(const Edge &o) const{
        return cost < o.cost;
    }
};

vector<int> dx{1,0,-1,0};
vector<int> dy{0,-1,0,1};

int main() {
    int H,W; cin >> H >> W;

    vector<vector<int>> G(H+2, vector<int>(W+2,0));
    vector<Edge> A(H*W);
    REP(i,H){
        REP(j,W){
            int a; cin >> a;
            A[i*W+j] = {i+1,j+1,a};
            G[i+1][j+1] = a;
        }
    }
    sort(ALL(A));
    vector<vector<ll>> dp(H+2, vector<ll>(W+2,1));

    REP(i,H*W){
        A[i].cost;
        int x = A[i].h;
        int y = A[i].w;
        REP(n,4){
            if(A[i].cost < G[x+dx[n]][y+dy[n]]){
                dp[x+dx[n]][y+dy[n]] += dp[x][y];
                dp[x+dx[n]][y+dy[n]] %= MOD;
            }
        }
    }
    ll ans = 0;
    REP(i,H){
        REP(j,W){
            ans += dp[i+1][j+1];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}