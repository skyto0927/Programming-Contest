#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (int)1e9
typedef long long ll;

//1 2 3 4 5 6 7 8 9
//2 5 5 4 5 6 3 7 6

//-> {1} {7} {4} {2,3,5} {6,9} {8}
//->  2   3   4     5      6    7

int main() {
    int N,M; cin >> N >> M;
    vector<int> A(10,INF);
    vector<int> cost{INF,2,5,5,4,5,6,3,7,6};
    REP(i,M){
        int a; cin >> a;
        A[a] = cost[a];
    }
    if(A[2]!=INF && A[3]!=INF) A[2]=INF;//わざわざ同じ本数で小さい数字を使う必要はない
    if(A[3]!=INF && A[5]!=INF) A[3]=INF;
    if(A[2]!=INF && A[5]!=INF) A[5]=INF;
    if(A[6]!=INF && A[9]!=INF) A[6]=INF;

    vector<vector<int>> dp(10, vector<int>(10100,-1));
    vector<vector<int>> prev(10, vector<int>(10100,-1));//復元用
    dp[0][0] = 0;
    REP(i,10){
        REP(j,N+1){
            if(dp[i][j]==-1) continue;
            if(j+A[i]<=N){
                if(dp[i][j+A[i]] <= dp[i][j]+1){
                    dp[i][j+A[i]] = dp[i][j]+1;
                    prev[i][j+A[i]] = j;
                }
            }
            if(i!=9){
                dp[i+1][j] = dp[i][j];
                prev[i+1][j] = j;
            }
        }
    }

    // REP(i,10){
    //     REP(j,N+1){
    //         cout << prev[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int cur = N;
    int i = 9;
    while(i!=0 || cur!=0){
        if(prev[i][cur] == cur){//縦に来た場合
            i--;
        }
        else{
            cur -= A[i];
            cout << i;
        }
    }
    cout << endl;

    //cout << prev[9][N] << endl;
    //cout << dp[9][N] << endl;
    return 0;
}