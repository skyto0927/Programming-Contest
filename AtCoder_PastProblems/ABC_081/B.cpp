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
    int ans = INF;
    REP(i,N){
        int a; cin >> a;
        int cnt = 0;
        while(a>0 && a%2==0){
            a /= 2;
            cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}