#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    long double N,K;
    cin >> N >> K;

    long double ans = 0;
    FOR(i,1,N+1){
        long double x = ceil(log2(K/i));
        if(x<= 0){
            ans += 1 / N;
        }else{
            ans += pow(0.5,x) / N;
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
