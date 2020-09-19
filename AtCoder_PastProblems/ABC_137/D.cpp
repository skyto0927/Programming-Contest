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
    int N,M; cin >> N >> M;
    priority_queue<int> q;
    vector<vector<int>> P(100100);
    REP(i,N){
        int a,b; cin >> a >> b;
        P[a].push_back(b);
    }

    ll ans = 0;

    FOR(i,1,M+1){
        //cout << i << " " << P[i].size() << endl;
        for(auto a: P[i]){
            q.push(a);
        }

        if(!q.empty()){
            //cout << q.top() << endl;
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}