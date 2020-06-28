#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N;
int N_MAX = 3e4;
vector<int> c(N_MAX);
vector<int> dp(N_MAX, INF);

int main() {
    cin >> N;
    REP(i,N){
        cin >> c[i];
        auto itr = lower_bound(ALL(dp), c[i]);
        *itr = c[i];
    }

    auto len = lower_bound(ALL(dp), INF);
    int ans = N - (len - dp.begin());

    cout << ans << endl;
    
    return 0;
}