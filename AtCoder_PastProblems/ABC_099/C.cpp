#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;

    vector<int> cost;
    cost.push_back(1);

    int six = 1;
    while(six*6 <= N){
        six *= 6;
        cost.push_back(six);
    }

    int nine = 1;
    while(nine*9 <= N){
        nine *= 9;
        cost.push_back(nine);
    }
    sort(ALL(cost));


    vector<vector<int>> dp(cost.size(), vector<int>(N+1, INF));
    dp[0][0] = 0;

    REP(i,cost.size()){
        REP(j,N+1){
            //同種
            if(j+cost[i] <= N){
                dp[i][j+cost[i]] = min(dp[i][j+cost[i]], dp[i][j]+1);
            }

            //下に移動
            if(i!=cost.size()-1){
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    cout << dp[cost.size()-1][N] << endl;

    return 0;
}