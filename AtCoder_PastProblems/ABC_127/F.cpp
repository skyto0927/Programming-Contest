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
    int Q; cin >> Q;
    vector<ll> A;
    priority_queue<ll> left;
    priority_queue<ll, vector<ll>, greater<ll> > right;
    left.push(-LINF);
    right.push(LINF);
    ll l_sum = 0;
    ll r_sum = 0;
    ll sum = 0;
    REP(i,Q){
        int q; cin >> q;
        if(q==1){
            ll a,b; cin >> a >> b;
            if(left.size() > right.size()){
                ll t = left.top();
                if(a >= t){
                    right.push(a); r_sum += a;
                }else{
                    left.pop(); l_sum -= t;
                    left.push(a); l_sum += a;
                    right.push(t); r_sum += t;
                }
            }else{
                ll t = right.top();
                if(a <= t){
                    left.push(a); l_sum += a;
                }else{
                    right.pop(); r_sum -= t;
                    right.push(a); r_sum += a;
                    left.push(t); l_sum += t;
                }
            }
            
            sum += b;

        }else{
            ll x = left.top();
            ll l = x*(left.size()-1) - l_sum;
            ll r = r_sum - x*(right.size()-1);
            cout << x << " " <<  l + r + sum << endl;
        }
    }
    return 0;
}