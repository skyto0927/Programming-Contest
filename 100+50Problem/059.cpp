#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N, K;
int N_MAX = 5e3;

struct edge
{
    int to, d;
};


vector<int> C(N_MAX);
vector<int> R(N_MAX);
vector<vector<int>> G(N_MAX);
vector<vector<edge>> G2(N_MAX);
vector<int> fee(N_MAX, INF);


void BFS(int i){
    vector<int> d(N_MAX, -1);
    queue<int> q;
    q.push(i);
    d[i] = 0;

    while (!q.empty()){
        auto p = q.front();
        q.pop();

        for(auto next: G[p]){
            if(d[next] == -1){
                d[next] = d[p] + 1;
                q.push(next);
            }
        }
    }
    REP(j,N){
        if(d[j] <= R[i] && i!=j){
            G2[i].push_back({j,C[i]});
        }
    }
    return;
}

void Dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0,0));
    fee[0] = 0;

    while(!q.empty()){
        auto p = q.top();
        q.pop();
        if(fee[p.second] < p.first) continue;

        for(auto next: G2[p.second]){
            if(fee[next.to] > fee[p.second] + next.d){
                fee[next.to] = fee[p.second] + next.d;
                q.push(make_pair(fee[next.to], next.to));
            }
        }
    }
}

    

int main() {
    cin >> N >> K;
    REP(i,N){
        cin >> C[i] >> R[i];
    }
    REP(j,K){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    REP(i,N){
        BFS(i);
    }

    Dijkstra();
    
    cout << fee[N-1] << endl;
    return 0;
}