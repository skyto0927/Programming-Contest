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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int num = 0;
    REP(i,n){
        num+= (s[i]=='I'?1:-1);
        ans = max(ans,num);
    }
    cout << ans << endl;
    return 0;
}