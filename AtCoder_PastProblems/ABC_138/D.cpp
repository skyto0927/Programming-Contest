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
    int N,Q; cin >> N >> Q;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> count(N,0);
    vector<bool> checked(N,false);
    REP(i,Q){
        int p,x; cin >> p >> x;
        p--;
        count[p] += x;
    }

    queue<int> q;
    q.push(0);
    checked[0] = true;

    while(!q.empty()){
        auto p = q.front(); q.pop();
        for(auto next: G[p]){
            if(checked[next] == true) continue;

            checked[next] = true;
            count[next] += count[p];
            q.push(next);
        }
    }

    REP(i,N) cout << count[i] << " ";
    cout << endl;
    return 0;
}