#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll N,A,B; cin >> N >> A >> B;

    ll d = A-B;
    vector<ll> h(N);
    REP(i,N) cin >> h[i];
    sort(ALL(h));

    int ng = -1;
    int ok = INF;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;

        vector<ll> H(h);
        REP(i,N) H[i] -= mid * B;
        int itr = upper_bound(ALL(H), 0) - H.begin();
        ll cnt = 0;
        FOR(i,itr,N){
            cnt += (H[i]-1)/d + 1;
        }
        if(mid >= cnt){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}