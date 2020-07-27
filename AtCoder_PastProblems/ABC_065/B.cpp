#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

vector<vector<int>> G;
vector<int> seen;

void dfs(int from, int pos, int cnt){
    cnt++;
    if(pos == 1){
        return;
    }

    for(int next: G[pos]){
        if(seen[next] != -1) return;
        else{
            seen[next] = cnt;
            dfs(pos,next,cnt);
        }
        
    }
}

int main() {
    int N; cin >> N;
    G.assign(N,{});
    seen.assign(N,-1);
    seen[0] = 0;

    REP(i,N){
        int a; cin >> a;
        a--;
        G[i].push_back(a);
    }

    dfs(-1,0,0);

    cout << seen[1] << endl;
    return 0;
}