#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int V,E;


vector<vector<int>> G(15,vector<int>(15,INF));

vector<vector<int>> dp((1<<15), vector<int>(15,-1));

int rec(int bit, int v){

    if (dp[bit][v] >= 0) return dp[bit][v];//メモ化

    if(bit==0){//初期化
        if(v==0){
            return 0;
        }else{
            return INF;
        }
    }

    if((bit&(1<<v)) == 0) return INF;//、矛盾する状態なら

    dp[bit][v] = INF;//ここからdp

    REP(i,V){
        dp[bit][v] = min(dp[bit][v], rec(bit^(1<<v),i) + G[i][v]);
    }
    return dp[bit][v];
}

int main() {
    cin >> V >> E;
    REP(i, E){
        int s,t,d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    int ans = rec((1<<V)-1, 0);

    if(ans == INF) ans = -1;

    cout << ans << endl;

    return 0;
}