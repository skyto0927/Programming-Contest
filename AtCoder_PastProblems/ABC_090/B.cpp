#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B; cin >> A >> B;
    int ans = 0;

    FOR(n,A,B+1){
        string s = to_string(n);
        string sr = s;
        reverse(ALL(sr));
        if(s == sr) ans++;
    }
    cout << ans << endl;
    return 0;
}