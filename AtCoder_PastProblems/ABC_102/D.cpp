#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<ll> S(N+1,0);
    REP(i,N) S[i+1] += S[i] + A[i];//[0,x) [x,y) [y,z) [z,N)に分割
    
    ll ans = 1e15;
    FOR(i,2,N-1){//yは2からN-2で全探索
        int y = i;

        //PQの境界を求める
        int ng = 0;
        int ok = y-1;
        while(abs(ok-ng)>1){
            int mid = (ok+ng)/2;
            if(S[mid] >= S[y]-S[mid]){//ここに条件をかく
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll x;
        if(abs(S[y]-2*S[ok]) < abs(S[y]-2*S[ng])) x = ok;
        else x = ng;

        //RSの境界も同様に
        ng = y;
        ok = N;
        while(abs(ok-ng)>1){
            int mid = (ok+ng)/2;
            if(S[mid]-S[y] >= S[N]-S[mid]){//ここに条件をかく
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll z;
        if(abs(S[N]-2*S[ok]+S[y]) < abs(S[N]-2*S[ng]+S[y])) z = ok;
        else z = ng;



        ll max_sum = max({S[x], S[y]-S[x], S[z]-S[y], S[N]-S[z]});
        ll min_sum = min({S[x], S[y]-S[x], S[z]-S[y], S[N]-S[z]});

        ans = min(ans, abs(max_sum - min_sum));
    }

    cout << ans << endl;
    return 0;
}