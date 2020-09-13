#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];

    int l = 0;
    int r = 0;
    ll sum = 0;
    ll ans = 0;
    while(r<N && l<N){
        sum += A[r];
        r++;
        while(sum>=K){
            //cout << l << " " << r << endl;
            sum -= A[l];
            l++;
            ans += N-r+1;
        }
        
    }
    cout << ans << endl;
    return 0;
}