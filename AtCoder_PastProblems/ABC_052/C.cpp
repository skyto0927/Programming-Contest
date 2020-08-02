#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;

void prime_fact(int n, map<int,int>& A){
    if (n <= 1) return;
    int n_origin = n;
    for(int i=2; i<=(int)sqrt(n_origin); i++){
        if (n%i == 0){
            int count = 0;
            while(n%i == 0){
                n/=i;
                count ++;
            }
            A[i] += count;
        }
    }
    if (n!=1){
        A[n] += 1;
    }
    return;
}

int main() {
    int n; cin >> n;
    map<int,int> A;
    FOR(i,1,n+1){
        prime_fact(i, A);
    }
    ll ans = 1;
    for(auto a: A){
        ans *= a.second+1;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}