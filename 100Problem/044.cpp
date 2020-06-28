#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;



int main() {
    int MAX = 10e6;

    vector<int> dp(MAX+1, INF);
    vector<int> odd_dp(MAX+1, INF);

    dp[0] = 0;
    odd_dp[0] = 0;


    // FOR(i,0,MAX+1){
    //     FOR(j,1,1000){
    //         int num = j*(j+1)*(j+2)/6;
    //         if (i+num > MAX) break;
    //         dp[i+num] = min(dp[i+num], dp[i]+1);
    //         if(num%2 == 1){
    //             odd_dp[i+num] = min(odd_dp[i+num], odd_dp[i]+1);
    //         }
    //     }
    // }

    FOR(j,1,1000){
        int num = j*(j+1)*(j+2)/6;
        if (num > MAX) break;
        FOR(i,0,MAX+1){
            if (i+num > MAX) break;
            dp[i+num] = min(dp[i+num], dp[i]+1);
            if(num%2 == 1){
                odd_dp[i+num] = min(odd_dp[i+num], odd_dp[i]+1);
            }
        }
    }

    while(1){
        int N;
        cin >> N;
        if (N == 0) break;

        cout << dp[N] << " " << odd_dp[N] << endl;

    }
    return 0;
}