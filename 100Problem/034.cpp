#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int n;
vector<int> dp;
int main() {
    cin >> n;
    dp.assign(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    FOR(i,2,n+1){//i=nまで計算！
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}
