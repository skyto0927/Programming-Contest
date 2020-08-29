#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MAX_N = 1000;
vector<vector<double>> dp(MAX_N+1,vector<double>(MAX_N+1,0));

void com_init(){
    dp[0][0] = 1.0;
    REP(n,MAX_N){
        REP(k,n+1){
            dp[n+1][k+1] += dp[n][k]/2.0;
            dp[n+1][k] += dp[n][k]/2.0;
        }
    }
}

int main() {
    int N,D; cin >> N >> D;
    int X,Y; cin >> X >> Y;
    X = abs(X);
    Y = abs(Y);

    double ans = 0.0;
    if(X%D!=0 || Y%D!=0){
        cout << ans << endl;
        return 0;
    }
    int x = X/D;
    int y = Y/D;  

    if((N-x-y)%2 != 0){
        cout << ans << endl;
        return 0;
    }

    int S = (N - x - y)/2;

    com_init();

    REP(i,S+1){
        ans += dp[N][x+2*i] * dp[x+2*i][i] * dp[y+2*(S-i)][S-i];
    }

    cout << fixed << setprecision(10) << ans << endl;


    return 0;
}