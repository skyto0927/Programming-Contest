#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

const int MOD = 1000000007;

int main() {
    int N,K;
    cin >> N >> K;
    
    vector<vector<int>> G(N);
    
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    
    ll ans = K;
    q.push(0);

    vector<bool> seen(N,false);

    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        seen[pos] = true;

        int count;
        if(pos == 0){
            count = K-1;
        }else{
            count = K-2;
        }
        
        for(auto next: G[pos]){
            if(seen[next]){
                continue;
            }else{
                q.push(next);
                if(count <= 0){
                    cout << 0 << endl;
                    return 0;
                }
                ans *= count;
                ans %= MOD;
                count--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}