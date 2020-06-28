#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


vector<bool> seen;
vector<int> d;
vector<int> f;
int timer;

void dfs(vector<vector<int>> &G, int v){
    seen[v] = true;
    timer ++;
    d[v] = timer;

    for (auto next: G[v]){
        if(seen[next]) continue;
        dfs(G, next);
    }
    timer ++;
    f[v] = timer;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n+1);//1_indexed
    int id, num;

    vector<int> ids(n+1);
    REP(i,n){
        cin >> id >> num;
        ids[i+1] = id;
        REP(j, num){
            int v;
            cin >> v;
            G[id].push_back(v);
        }
    }

    seen.assign(n, false);

    d.assign(n+1,0);
    f.assign(n+1,0);

    

    timer = 0;
    dfs(G,1);

    REP(i,n){
        cout << ids[i+1] << " " << d[i+1] << " " << f[i+1] << endl;
    }
    

    return 0;
}
