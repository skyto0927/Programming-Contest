#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,C; cin >> N >> C;
    vector<pair<ll,ll>> sushi(2*N+1);
    sushi[N] = make_pair(0,0);
    FOR(i,1,N+1){
        ll x,v;
        cin >> x >> v;
        sushi[N-i] = make_pair(x,v);
        sushi[2*N+1-i] = make_pair(C-x,v);
    }

    vector<ll> memo_return(2*N+1, 0);//左か右に行き、いったん原点に戻る
    vector<ll> memo(2*N+1, 0);//左か右に行って退店
    FOR(i,1,N+1){
        memo[N-i] += memo[N-i+1] + sushi[N-i+1].first - sushi[N-i].first + sushi[N-i].second;
        memo[N+i] += memo[N+i-1] + sushi[N+i-1].first - sushi[N+i].first + sushi[N+i].second;
    }
    FOR(i,1,N+1){
        memo[N-i] = max(memo[N-i+1], memo[N-i]);
        memo[N+i] = max(memo[N+i-1], memo[N+i]);
        memo_return[N-i] = max(memo_return[N-i+1], memo[N-i]-sushi[N-i].first);
        memo_return[N+i] = max(memo_return[N+i-1], memo[N+i]-sushi[N+i].first);
    }

    
    ll ans = 0;
    REP(i,N+1){
        ans = max(ans, memo[i]+memo_return[N+i]);
        ans = max(ans, memo_return[i]+memo[N+i]);
    }

    cout << ans << endl;
    return 0;
}