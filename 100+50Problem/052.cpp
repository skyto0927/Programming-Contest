#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N,M;

vector<int> doll_num(20,0);
vector<int> dp(1<<20, -1);
vector<int> len(1<<20, 0);

vector<vector<int>> doll_array(20,vector<int>(100001,0));

void rec(int bit){
    if (dp[bit] != -1) return;

    if (bit==0){
        REP(i,M){
            dp[1<<i] = doll_array[i][doll_num[i]] - doll_array[i][0];
            len[1<<i] = doll_num[i];
        }
        return;
    }



    REP(i,M){

        if (!(bit&(1<<i))) continue;

        rec(bit^(1<<i));

        len[bit] = len[bit^(1<<i)]+doll_num[i];

        int stay = doll_array[i][len[bit]] - doll_array[i][len[bit^(1<<i)]];

        dp[bit] = max(dp[bit], dp[bit^(1<<i)] + stay);
    }
    return;
    
}
    
/*
言い換えて、種類ごとにまとめて配置したとき、初めの配置と一致する個数が最大になるように
計算する
*/

int main() {
    cin >> N >> M;

    
    FOR(i,1,N+1){
        int num;
        cin >> num;
        num--;//0-indexed
        doll_array[num][i] = 1;
    }

    REP(m,M){//累積和で計算量省略したい
        FOR(n,1,N+1){
            doll_array[m][n] += doll_array[m][n-1];
        }
        doll_num[m] = doll_array[m][N];
    }

    rec((1<<M)-1);


    cout << N-dp[(1<<M)-1] << endl;


    
    return 0;
}