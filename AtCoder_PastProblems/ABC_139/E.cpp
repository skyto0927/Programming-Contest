#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

int N;

vector<int> dis(1000000,0), seen(1000000,0);
int dfs(vector<vector<int>> &g, int pos){
    if(seen[pos] == 2){
        return dis[pos];
    }
    seen[pos] = 1;

    for(auto j: g[pos]){
        if(seen[j] == 1){
            cout << -1 << endl;
            exit(0);
        }

        dis[pos] = max(dis[pos], dfs(g, j)+1);
    }
    seen[pos] = 2;
    return dis[pos];
}

int main() {
    cin >> N;
    vector<vector<int>> g(N*(N-1)/2+1);
    REP(i,N){
        vector<int> A(N-1);
        REP(j,N-1){
            int a; cin >> a;
            a--;
            if(i<a){
                A[j] = a*(a-1)/2 + i+1;
            }else{
                A[j] = i*(i-1)/2 + a+1;
            }
        }

        g[0].push_back(A[0]);
        
        REP(j,N-2){
            g[A[j]].push_back(A[j+1]);
        }
    }

    // REP(i,N*(N-1)/2+1){
    //     REP(j,N*(N-1)/2+1){
    //         cout << (g[i][j]==INF?0:1) << " ";
    //     }
    //     cout << endl;
    // }

    //dis.assign(N*(N-1)/2+1, -1);
    //seen.assign(N*(N-1)/2+1, 0);//探索中→1、探索後→2
    //dis[0] = 0;
    
    int ans = dfs(g,0);
    cout << ans << endl;

    return 0;
}