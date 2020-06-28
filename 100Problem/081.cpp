#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int n; cin >> n;
    vector<int> colors(1010000, 0);
    REP(i,n){
        int a,b;
        cin >> a >> b;
        colors[a] ++;
        colors[b+1] --;
    }

    int ans = 0;
    REP(i,1001000){
        colors[i+1] += colors[i];
        ans = max(ans, colors[i]);
    }

    cout << ans << endl;
    return 0;
}