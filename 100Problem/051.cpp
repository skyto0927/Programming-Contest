#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int N_MAX = 1000;
int N;
string S;

int JOI(char s){
    switch (s){
        case 'J':
            return 0;
        case 'O':
            return 1;
        case 'I':
            return 2;
    }
    return -1;
}

vector<vector<int>> dp((1<<3), vector<int>(1000,0));

int main() {
    cin >> N;
    cin >> S;

    REP(i,1<<3){//初期化
        if (i&(1<<0) && i&(1<<JOI(S[0]))){
            dp[i][0] = 1;
        }
    }

    FOR(i,1,N){
        REP(j,1<<3){
            REP(k,1<<3){
                if(j&k && k&(1<<JOI(S[i]))) {//i-1日目とi日目で人が重複　かつ　i日目に担当者がいる
                    dp[k][i] += dp[j][i-1];
                    dp[k][i] %= 10007;
                }
            }
        }
    }


    int ans = 0;

    REP(i,1<<3){
        ans += dp[i][N-1];
        ans %= 10007;
    }

    cout << ans << endl;



    return 0;
}