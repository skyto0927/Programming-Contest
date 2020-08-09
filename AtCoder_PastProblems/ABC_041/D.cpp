#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<ll> dp(1<<16, -1);
vector<vector<int>> G(16);
int N,M;

ll solve(int s){
    if(s==0){
        dp[0] = 1;
        return 1;
    }
    if(dp[s]!=-1){
        return dp[s];
    }else{
        dp[s] = 0;
        REP(i,N){
            if(!(s & (1<<i))) continue;
            bool ok = true;
            for(auto k: G[i]){
                if(!(s & (1<<k))){
                    ok = false;
                    break;
                }
            }
            if(ok) dp[s] += solve(s & ~(1<<i));
        }
    }
    return dp[s];
}


int main() {
    cin >> N >> M;
    REP(i,M){
        int x,y; cin >> x >> y;
        x--;
        y--;
        G[y].push_back(x);
    }

    cout << solve((1<<N)-1) << endl;

    return 0;
}