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
    vector<int> P(N);
    REP(i,N){
        int p; cin >> p;
        p--;
        P[i] = p;
    }
    int ans = 0;
    REP(i,N){
        if(P[i]==i){
            if(i!=N-1) swap(P[i],P[i+1]);
            else swap(P[i],P[i-1]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}