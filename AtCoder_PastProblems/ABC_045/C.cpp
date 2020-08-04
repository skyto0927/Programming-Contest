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
    string s; cin >> s;
    int N = s.size();
    ll ans = 0;
    REP(i,N){
        REP(k,N-2-i+1){
            ans += (s[i]-'0') * pow(10,k) * pow(2,N-2-k);
        }
        ans += (s[i]-'0') * pow(10,N-1-i) * pow(2,i);
    }

    cout << ans << endl;

    return 0;
}