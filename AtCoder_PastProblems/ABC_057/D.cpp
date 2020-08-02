#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


//iCj = i-1Cj-1 + i-1Cj
vector<vector<ll>> dp(60,vector<ll>(60,0));

void com_init(){
    REP(i,55){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    FOR(n,1,55){
        FOR(k,1,n){
            dp[n][k] = dp[n-1][k-1] + dp[n-1][k];
        }
    }
}

ll com(int n, int k){
    
    return dp[n][k];
}


int main() {
    com_init();
    int N,A,B; cin >> N >> A >> B;
    map<ll,int> V;

    ll v_max = 0;
    REP(i,N){
        ll v; cin >> v;
        v_max = max(v_max, v);
        V[-v]++;
    }

    int cnt = 0;
    double ans = 0.0;
    for(auto v: V){
        if(A <= cnt + v.second){
            if((-v.first) == v_max){
                cout << fixed << setprecision(6) << (double)-v.first << endl;

                ll num = 0;
                FOR(k,A,min(v.second,B)+1){
                    num += com(v.second,k);
                }
                cout << num << endl;
                return 0;
            }else{
                ans += -v.first * (A-cnt);
                cout << fixed << setprecision(6) << ans/A << endl;
                cout  << com(v.second, A-cnt) << endl;
                return 0;
            }
        } else{
            cnt += v.second;
            ans += -v.first * v.second;
        }
    }
    return 0;
}