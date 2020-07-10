#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string S; cin >> S;
    int ans = INF;
    REP(i,S.size()-2){
        int x = 100*(S[i]-'0') + 10*(S[i+1]-'0') + (S[i+2]-'0');
        ans = min(ans, abs(753-x));
    }

    cout << ans << endl;
    return 0;
}