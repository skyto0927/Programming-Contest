#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;

    vector<ll> A(N), F(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> F[i];
    sort(ALL(A), greater<ll>());
    sort(ALL(F));


    ll ng = -1;
    ll ok = 1e12;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        ll sum = 0;
        REP(i,N){
            ll x = mid/F[i];
            sum += max(0ll,A[i]-x);
            if(sum > K) break;
        }
        //cout << mid << ", " << sum << endl;
        if(sum <= K){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}