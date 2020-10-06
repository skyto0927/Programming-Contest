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

ll digit(ll x){
    ll ans = 0;
    while(x>0){
        ans++;
        x /= 10;
    }
    return ans;
}

int main() {
    ll a,b,x; cin >> a >> b >> x;

    ll ng = 1e9+1;
    ll ok = 0;

    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        
        if(a*mid + b*digit(mid) <= x){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
}