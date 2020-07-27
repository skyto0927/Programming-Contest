#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

ll solve(ll h, ll w){
    ll ans = 1e15;
    ll num;
    if(h%2==0){
        FOR(k,1,w){
            num = max(h*k,(h/2)*(w-k)) - min(h*k,(h/2)*(w-k));
            ans = min(ans, num);
        }
    }else{
        FOR(k,1,w){
            num = max({h*k,(h/2)*(w-k), (h/2+1)*(w-k)}) 
                - min({h*k,(h/2)*(w-k), (h/2+1)*(w-k)});
            ans = min(ans, num);
        }
    }
    return ans;
}

int main() {
    ll H,W; cin >> H >> W;
    if(H%3==0 || W%3==0) cout << 0 << endl;
    else{
        cout << min({solve(H,W), solve(W,H), H, W}) << endl;
    }
    return 0;
}