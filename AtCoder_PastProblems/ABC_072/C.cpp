#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> table(100100,0);
    REP(i,N){
        int a; cin >> a;
        table[a] ++;
    }

    int ans = 0;
    FOR(i,1,100000){
        ans = max(ans, table[i-1]+table[i]+table[i+1]);
    }
    cout << ans << endl;
    return 0;
}