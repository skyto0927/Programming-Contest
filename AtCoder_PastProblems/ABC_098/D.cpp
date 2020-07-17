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
    vector<ll> A(N,0);
    REP(i,N) cin >> A[i];

    ll num = 0;

    int r = 0;
    ll ans = 0;
    REP(l,N){
        while(r<N){
            if(num+A[r] == (num^A[r])){
                num += A[r];
                r++;
                ans++;
            }else{
                break;
            }
        }
        num -= A[l];
        ans += r-l;
    }
    ans -= N;//[n,n)のような、1個も含まれないものがあるため消す
    cout << ans << endl;

    return 0;
}