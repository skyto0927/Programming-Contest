#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<int> score;
vector<int> memo;

int value;

void dfs(vector<vector<int>> &G, int v, int parent){
    value += memo[v];
    score[v] = value;

    for (auto next: G[v]){
        if (next == parent)continue;
        dfs(G, next, v);
    }
    value -= memo[v];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N+1);//1-indexed
    REP(i, N-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    score.assign(N+1, 0);

    memo.assign(N+1, 0);
    REP(i,Q){
        int p, x;
        cin >> p >> x;
        memo[p] += x;
    }

    value = 0;
    dfs(G, 1, -1);

    REP(i,N){
        cout << score[i+1];
        if(i!=N-1) cout << " ";
        else cout << endl;
    }

    return 0;
}
