#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,A,B; cin >> N >> A >> B;
    int ans = 0;
    FOR(i,1,N+1){
        int n = i;
        int s = 0;
        while(n>0){
            s += n%10;
            n /= 10;
        }
        if(A<=s && s<=B) ans += i;
    }
    cout << ans << endl;

    return 0;
}