#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

ll digits(ll N, int num){
    ll n = N;
    ll ans = 0;
    while(n%num == 0){
        n /= num;
        ans++;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    vector<vector<ll>> twofive(19, vector<ll>(19,0));
    
    REP(i,N){
        double a; cin >> a;
        a *= 1e9;
        A[i] = (ll)round(a);
        
        int t = digits(A[i],2);
        int f = digits(A[i],5);
        twofive[min(t,18)][min(f,18)] ++;
    }
    // REP(i,19){
    //     REP(j,19){
    //         cout << twofive[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<ll>> twofive_origin(twofive);

    FOR(i,1,19){
        for(int j=18; j>=1; j--){
            twofive[i][j-1] += twofive[i][j];
        }
    }
    FOR(j,1,19){
        for(int i=18; i>=1; i--){
            twofive[i-1][j] += twofive[i][j];
        }
    }
    ll ans = 0;
    REP(i,19){
        REP(j,19){
            if(twofive_origin[i][j] == 0) continue;
            int t0 = 18-i;
            int f0 = 18-j;
            if(t0<=i && f0<=j) ans += twofive_origin[i][j]*(twofive[t0][f0]-1);
            else ans += twofive_origin[i][j]*twofive[t0][f0];
            //cout << i << " " << j << " " << ans << endl;
        }
    }

    cout << ans/2LL << endl;
    return 0;
}