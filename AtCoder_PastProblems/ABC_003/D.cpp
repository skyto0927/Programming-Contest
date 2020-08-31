#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;
int R,C,X,Y,D,L;

vector<vector<ll>> dp(1000,vector<ll>(1000,0));
void com_init(){
    REP(i,1000){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    FOR(n,1,1000){
        FOR(k,1,n){
            dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
            dp[n][k] %= MOD;
        }
    }
}


int main() {
    com_init();
    cin>>R>>C>>X>>Y>>D>>L;

    ll ans = 0;

    REP(bit,16){
        int cnt = 0;
        int x = X;
        int y = Y;
        REP(i,4){
            if(bit & (1<<i)){
                cnt++;
                if(i==0 || i==1) x--;
                if(i==2 || i==3) y--;
            }
        }
        if(x>=0 && y>=0 && x*y >= D+L){//dp利用可能なら
            ans += dp[x*y][D+L] * (cnt%2?-1:1);
            ans = (ans+MOD) % MOD;
        }
    }

    ans *= dp[D+L][D];
    ans %= MOD;

    ans *= (R-X+1)*(C-Y+1);
    ans %= MOD;
    cout << ans << endl;

    return 0;
}