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

    vector<int> table(1e7+1,0);
    FOR(x,1,100){
        FOR(y,1,100){
            FOR(z,1,100){
                int n = x*x + y*y + z*z + x*y + y*z + z*x;
                table[n]++;
            }
        }
    }

    FOR(i,1,N+1){
        cout << table[i] << endl;
    }

    return 0;
}