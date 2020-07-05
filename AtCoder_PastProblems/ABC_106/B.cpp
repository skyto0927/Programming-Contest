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
    vector<int> table(300,0);
    FOR(i,1,N+1){
        int x = i;
        while(x<= N){
            table[x] ++;
            x += i;
        }
    }

    int ans = 0;
    REP(i,N+1){
        if(i%2==1 && table[i]==8){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}