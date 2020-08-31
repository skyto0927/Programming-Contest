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
    vector<int> table(n+1,0);
    table[1] = 0;
    table[2] = 0;
    table[3] = 1;
    if(n <= 3){
        cout << table[n] << endl;
        return 0;
    }
    FOR(i,4,n+1){
        table[i] = table[i-1] + table[i-2] + table[i-3];
        table[i] %= 10007;
    }
    cout << table[n] << endl;
    return 0;
}