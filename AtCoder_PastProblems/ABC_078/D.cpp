#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N,Z,W;
vector<vector<int>> dp(2010, vector<int>(2,-1));
vector<int> A;

int dfs(int pos, int t){
    if(dp[pos][t] != -1) return dp[pos][t];

    int ret;
    if(t==0) ret = 0;//先手なら最大化のため最小値
    else ret = INF;//後手なら最小化のため最大値

    FOR(i,pos+1,N+2){//前の人は必ずposを選んでいる
        int tmp;
        if(i==N+1) tmp = abs(A[pos] - A[N+1]);//最後を選ぶ場合
        else tmp = dfs(i,1-t);//そうでなければA[i]を選び、手番交代

        if(t==0) ret = max(ret,tmp);//先手なら最大値を
        else ret = min(ret,tmp);//後手なら最小値を
    }
    dp[pos][t] = ret;//計算結果はメモ
    return ret;
}

int main() {
    cin >> N >> Z >> W;
    A.assign(N+2,0);
    A[0] = Z;
    A[1] = W;
    FOR(i,2,N+2) cin >> A[i];

    


    cout << dfs(1,0) << endl;//後手がA[1] = Wを選択した場合なので初期条件と同じ
    //1個も取らないことはあり得ないので、先手が最初に持っていた値は実は無意味！！

    return 0;
}