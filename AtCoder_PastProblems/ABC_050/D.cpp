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
string digit(ll N){
    string ans;
    while(N>0){
        ans += (N%2==0?'0':'1');
        N/=2;
    }
    reverse(ALL(ans));
    return ans;
}

int main() {
    ll N; cin >> N;
    string s = digit(N);
    vector<vector<ll>> dp(s.size()+1,vector<ll>(3,0));
    dp[0][0] = 1;

    //dp[digit][state];
    REP(i,s.size()){
        REP(x,3){
            REP(k,3){
                int next = min(2,2*x+(s[i]-'0')-k);
                if(0<=next){
                    dp[i+1][next] += dp[i][x];
                    dp[i+1][next] %= MOD;//u-vの上位ibitを取り出して比較したとき2以上の差があると、それ以降決して超えることはない！！
                }
            }
        }
    }
    ll ans = 0;
    REP(i,3){
        ans += dp[s.size()][i];
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}