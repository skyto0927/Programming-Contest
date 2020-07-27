#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e15
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<ll> a(3*N);
    REP(i,3*N) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> L;
    priority_queue<ll> R;
    vector<ll> l_sum(N+1,0);
    vector<ll> r_sum(N+1,0);

    REP(i,N){
        L.push(a[i]);
        l_sum[0] += a[i];
    }
    REP(i,N){
        if(L.top() < a[N+i]){
            l_sum[i+1] = l_sum[i] + a[N+i] - L.top();
            L.pop();
            L.push(a[N+i]);
        }else{
            l_sum[i+1] = l_sum[i];
        }
    }

    REP(i,N){
        R.push(a[3*N-1-i]);
        r_sum[0] += a[3*N-1-i];
    }
    REP(i,N){
        if(R.top() > a[2*N-1-i]){
            r_sum[i+1] = r_sum[i] + a[2*N-1-i] - R.top();
            R.pop();
            R.push(a[2*N-1-i]);
        }else{
            r_sum[i+1] = r_sum[i];
        }
    }

    reverse(ALL(r_sum));

    ll ans = - LINF;
    REP(i,N+1){
        //cout << l_sum[i] << ", " << r_sum[i] << endl;
        ans = max(ans,l_sum[i] - r_sum[i]);
    }
    cout << ans << endl;
    

    return 0;
}