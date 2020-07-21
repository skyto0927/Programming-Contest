#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e15
typedef long long ll;

struct Edge{
    int to,dist;
};

int main() {
    int N,M; cin >> N >> M;

    vector<vector<Edge>> G(N);
    REP(i,M){
        int L,R,D; cin >> L >> R >> D;
        L--;
        R--;
        G[L].push_back({R,D});
        G[R].push_back({L,-D});
    }

    vector<ll> X(N,LINF);

    
    REP(i,N){
        if(X[i] == LINF){
            X[i]=0;

            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int pos = q.front(); q.pop();
                
                for(auto next: G[pos]){
                    if(next.to == pos) continue;

                    if(X[next.to] == LINF){
                        X[next.to] = X[pos] + next.dist;
                        q.push(next.to);
                    }else{
                        if(X[next.to] != X[pos] + next.dist){
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "Yes" << endl;




    return 0;
}