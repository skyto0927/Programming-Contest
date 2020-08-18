#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int dfs(vector<vector<int>> G, vector<int>& pay, int pos){
    if(pay[pos] != -1){
        return pay[pos];
    }

    int p_max = 0;
    int p_min = INF;
    for(auto next: G[pos]){
        int p = dfs(G,pay,next);
        pay[next] = p;
        p_max = max(p_max, p);
        p_min = min(p_min, p);
    }
    if(p_min == INF) p_min = 0;
    pay[pos] = p_max + p_min + 1;
    return p_max + p_min + 1;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int b; cin >> b;
        b--;
        G[b].push_back(i+1);
    }

    vector<int> pay(N,-1);
    REP(i,N){
        dfs(G,pay,i);
    }
    cout << pay[0] << endl;
    return 0;
}