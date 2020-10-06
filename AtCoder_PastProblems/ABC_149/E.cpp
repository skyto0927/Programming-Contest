#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,M; cin >> N >> M;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    sort(ALL(A));

    vector<ll> sum(N+1,0);
    REP(i,N){
        sum[i+1] = sum[i] + A[i];
    }

    ll ng = 0;
    ll ok = 1000000;
    ll cnt = 0;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        cnt = 0;
        
        REP(i,N){
            ll cur = A.end() - lower_bound(ALL(A), mid-A[i]);//繋いだ値の和がmid以上
            cnt += cur;
        }
        if(cnt<M){//まだ手をつなげる余地があるので、ボーダーを下げる
            ok = mid;
        }else{//実はここの等号はどっちでもいい
            ng = mid;
        }
    }

    ll ans = 0;
    cnt = 0;
    REP(i,N){
        ll cur = A.end() - lower_bound(ALL(A), ok-A[i]);
        ans += A[i]*cur + sum[N]-sum[N-cur];
        cnt += cur;
    }

    //cout << ok << endl;
    //cout << cnt << endl;
    cout << ans + (ok-1)*(M-cnt) << endl;
    return 0;
}