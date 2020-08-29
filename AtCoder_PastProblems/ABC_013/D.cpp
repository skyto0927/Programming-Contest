#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    int N,M,D; cin >> N >> M >> D;
    vector<int> A(N);
    REP(i,N) A[i] = i;
    REP(i,M){
        int a; cin >> a;
        a--;
        swap(A[a], A[a+1]);
    }
    
    

    int K = 1;
    while((1<<K) <= D) K ++;
    vector<vector<int>> parent(K, vector<int>(N,-1));

    REP(i,N) parent[0][A[i]] = i;

    REP(k,K-1){
        REP(i,N){
            if(parent[k][i]<0){
                parent[k+1][i] = -1;
            }else{
                parent[k+1][i] = parent[k][parent[k][i]];
            }
        }
    }
    REP(i,N){
        int ans = i;
        REPR(k,K){
            if(1<<k & D){
                ans = parent[k][ans];
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}