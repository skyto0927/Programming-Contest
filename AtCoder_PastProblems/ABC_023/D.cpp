#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> H(N), S(N);
    ll maxH = 0;
    ll maxS = 0;

    REP(i,N){
        cin >> H[i] >> S[i];
        maxH = max(maxH,H[i]);
        maxS = max(maxS,S[i]);
    }

    ll ng = maxH-1;
    ll ok = maxH+(N-1)*maxS;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;

        vector<ll> sum(N);
        REP(i,N) sum[i] = (mid-H[i])/S[i];
        sort(ALL(sum));
        bool isok = true;
        REP(i,N) if(sum[i] < i) isok = false;
        if(isok){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}