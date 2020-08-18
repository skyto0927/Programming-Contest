#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<int> dp(pow(3,9), -INF);

vector<vector<int>> B(2,vector<int>(3));
vector<vector<int>> C(3,vector<int>(2));

int solve(int n, int turn){
    if(dp[n]!=-INF) return dp[n];

    int mark = 1;//chokudaiは1
    if(turn%2 == 1) mark = 2;//naokoは2
    string S;
    int s = n;
    REP(i,9){
        S += (to_string(s%3));
        s /= 3;
    }

    if(turn == 9){
        int sum = 0;
        REP(i,2) REP(j,3) sum += (S[3*i+j]==S[3+3*i+j]?B[i][j]:-B[i][j]);
        REP(i,3) REP(j,2) sum += (S[3*i+j]==S[1+3*i+j]?C[i][j]:-C[i][j]);
        dp[n] = sum;
        return dp[n];
    }

    int max_score = -INF;
    int min_score = INF;
    //reverse(ALL(S));
    REP(i,9){
        if(S[i]=='0'){
            int tmp = solve(n+mark*pow(3,i), turn+1);
            max_score = max(max_score, tmp);
            min_score = min(min_score, tmp);
        }
    }
    dp[n] = mark==1?max_score:min_score;
    return dp[n];
}


int main() {
    int sum;
    REP(i,2) REP(j,3) cin >> B[i][j], sum += B[i][j];
    REP(i,3) REP(j,2) cin >> C[i][j], sum += C[i][j];

    //ans, sum-ans

    int ans = solve(0,0);
    cout << (sum+ans)/2 << endl;
    cout << (sum-ans)/2 << endl;
    return 0;
}