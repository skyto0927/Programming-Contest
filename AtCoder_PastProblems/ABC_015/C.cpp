#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int N,K; 

vector<vector<int>> G;

bool solve(int n, int x){
    if(n==N){
        return (x==0?false:true);
    }
    bool ok = true;
    REP(i,K){
        if(!solve(n+1, x^G[n][i])){
            ok = false;
        }
    }
    return ok;
}

int main() {
    cin >> N >> K;

    G.assign(N,vector<int>(K,0));
    REP(i,N){
        REP(j,K){
            cin >> G[i][j];
        }
    }

    cout << (solve(0,0)?"Nothing":"Found") << endl;

    return 0;
}