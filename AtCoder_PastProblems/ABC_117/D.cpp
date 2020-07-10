#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    vector<ll> bit(50, 0);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
        REP(b, 50){
            ll p = pow((ll)2, (ll)b);
            if(a & p){
                bit[b]++;
            }
        }
    }

    ll x = 0;
    REPR(b,49){
        if(bit[b] < N-bit[b]){//0の方が多ければ
        ll d = pow((ll)2,(ll)b);
            if(x + d <= K){
                //cout << d << endl;
                x += d;
            }
        }
    }

    ll ans = 0;
    REP(i,N){
        ans += x^A[i];
    }

    cout << ans << endl;
    
    return 0;
}