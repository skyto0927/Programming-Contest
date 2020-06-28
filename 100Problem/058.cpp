#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e15
typedef long long ll;

ll N_MAX = 1e5;
ll N,M,K,S;
ll P,Q;
vector<ll> C(N_MAX);

using Pair = pair<ll,ll>;

vector<vector<ll>> G(N_MAX);
vector<ll> danger(N_MAX,-1);

vector<ll> cost(N_MAX, INF);
vector<ll> dist(N_MAX, INF);

int main() {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    REP(i,K){
        cin >> C[i];
        C[i]--;//0-indexed
        danger[C[i]] = 0;
    }


    REP(i,M){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);//0-indexed
        G[b-1].push_back(a-1);
    }


    //BFSで危険な街を判別

    queue<Pair> bfs_que;

    REP(i,K){
        bfs_que.push(Pair(C[i],S));
    }

    while(!bfs_que.empty()){
        Pair pp = bfs_que.front();
        bfs_que.pop();


        for(auto nex: G[pp.first]){
            if (danger[nex] == -1){//未踏破なら
                danger[nex] = danger[pp.first] + 1;
                bfs_que.push(Pair(nex, danger[nex]));
            }
        }
    }

    REP(i,N){
        if(danger[i] <= S && danger[i] > 0){//危険
            cost[i] = Q;
        }else if (danger[i] > S){
            cost[i] = P;
        }
    }
    cost[N-1] = 0;




    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.push(Pair(0,0));
    dist[0] = 0;

    while(!q.empty()){
        Pair p = q.top();
        q.pop();
        int v = p.second;

        if(dist[v] < p.first) continue;

        for(auto next: G[v]){
            if (dist[next] > dist[v] + cost[next]){
                dist[next] = dist[v] + cost[next];
                q.push(Pair(dist[next], next));
            }
        }
    }
    cout << dist[N-1] << endl;
    
    return 0;
}