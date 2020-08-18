#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const ll MAXS = 3000;

using P = pair<ll, ll>;
//using Edge = pair<int, P>;
ll N,M,S;


struct Edge{
    ll to,money,time;
    bool operator<(const Edge &o) const{
        return money < o.money;
    }
};

template<class T> void dijkstra(vector<vector<Edge>>& G, int s, vector<T>& dis){
    S = min(S,MAXS);
    vector<vector<ll>> dp(N,vector<ll>(MAXS+1,LINF));
    dis.resize(N,LINF);
    priority_queue<pair<ll,P>, vector<pair<ll,P>>, greater<pair<ll,P>> > q;

    dp[0][S] = 0;

    q.push({0,{0,S}});
    while(!q.empty()){
        auto p = q.top(); q.pop();

        ll time = p.first;
        int v = p.second.first;//頂点
        ll s = p.second.second;//所持金


        if(time > dp[v][s]) continue;

        for(auto next: G[v]){
            if(0 <= s+next.money){//料金が範囲内なら
                
                if(s==MAXS && next.money>0) continue;//所持金を増やす必要がないならパス

                int next_S = min(MAXS, s+next.money);
                if(dp[next.to][next_S] > time+next.time){//更新可能なら
                    dp[next.to][next_S] = time+next.time;
                    q.push({time+next.time, {next.to, next_S}});
                }
            }
        }     
    }

    REP(i,N){
        REP(j,MAXS+1){
            dis[i] = min(dis[i], dp[i][j]);
        }
    }
}


int main() {
    cin >> N >> M >> S;
    vector<vector<Edge>> G(N);
    REP(i,M){
        ll u,v,a,b; cin >> u >> v >> a >> b;
        u--;
        v--;
        G[u].push_back({v,-a,b});
        G[v].push_back({u,-a,b});
    }
    REP(i,N){
        ll c,d; cin >> c >> d;
        G[i].push_back({i,c,d});
    }

    vector<ll> dis;
    dijkstra(G,0,dis);

    FOR(i,1,N) cout << dis[i] << endl;

    return 0;
}