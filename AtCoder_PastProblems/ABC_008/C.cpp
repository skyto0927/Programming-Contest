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
    int N; cin >> N;
    map<int,int> C;
    REP(i,N){
        int c;  cin >> c;
        C[c]++;
    }

    double ans = 0;

    for(auto n: C){
        int cnt = -1;
        for(auto m: C){
            if(n.first%m.first == 0) cnt += m.second;
        }

        if(cnt%2==1) ans += 0.5*n.second;
        else ans += (cnt+2.0)/(2.0*cnt+2.0) * n.second;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}