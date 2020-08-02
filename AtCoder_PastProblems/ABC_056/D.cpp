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
    int N,K; cin >> N >> K;
    vector<int> A;
    REP(i,N){
        int a; cin >> a;
        if(a < K) A.push_back(a);
    }

    N = A.size();
    sort(ALL(A));
    int ng = (int)A.size();
    int ok = -1;

    while(abs(ok-ng)>1){
        //cout << ng << ", " << ok << endl;
        int mid = (ok+ng)/2;


        vector<vector<int>> dp(N+1, vector<int>(K, 0));
        dp[0][0] = 1;
        REP(i,N){
            REP(j,K){
                dp[i+1][j] |= dp[i][j];//縦の更新は常に

                if(j+A[i]<K && i!=mid){
                    dp[i+1][j+A[i]] |= dp[i][j];
                }
            }
        }
        REP(j,K-1) dp[N][j+1] += dp[N][j];
        int itr = lower_bound(ALL(dp[N]), dp[N][K-1]) - dp[N].begin();

        //cout << " " << itr << ", " << A[mid] << endl;
        if(itr + A[mid] < K){//ここに条件をかく
            ok = mid;
        }else{
            ng = mid;
        }
    }

    //cout << ng << ", " << ok << endl;
    cout << ok+1 << endl;
    return 0;
}