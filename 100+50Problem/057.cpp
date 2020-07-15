#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

using P = pair<int,int>;
int n,k;
int n_max = 100;

struct edge{
    int to,d;
};

vector<vector<edge>> G(n_max);

int main() {
    cin >> n >> k;
    vector<int> ans;
    REP(i,k){
        int x;
        cin >> x;
        if (x == 0){
            int a,b;
            cin >> a >> b;

            priority_queue<P, vector<P>, greater<P>> q;

            q.push(P(0,a-1));//d,vの順番
            vector<int> dist(n,INF);

            dist[a-1] = 0;
            while(!q.empty()){
                P p = q.top();
                q.pop();
                int v = p.second;


                if (dist[v] < p.first) continue;
                for (auto edge: G[v]){
                    if (dist[edge.to] > dist[v] + edge.d){
                        dist[edge.to] = dist[v] + edge.d;
                        q.push(P(dist[edge.to], edge.to));
                    }
                }
            }
            if (dist[b-1] == INF){
                ans.push_back(-1);
            }else{
                ans.push_back(dist[b-1]);
            }

        }else if(x == 1){
            int c,d,e;
            cin >> c >> d >> e;
            G[c-1].push_back({d-1,e});
            G[d-1].push_back({c-1,e});
        }
    }

    REP(i,ans.size()){
        cout << ans[i] << endl;
    }
    
    return 0;
}