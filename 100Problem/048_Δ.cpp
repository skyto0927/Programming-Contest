#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;




int main() {
    while(1){
        int n;
        cin >> n;
        if (n == 0)break;

        vector<int> w(n);
        REP(i,n) cin >> w[i];

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int width=2; width<=n; width++){//もらうDP
            FOR(left,0,n-width+1){
                int right = left+width-1;
                if(width%2==0 && dp[left+1][right-1]==width-2){//内側の区間が適切に処理でき、
                    if(abs(w[left] - w[right])<=1){//端の差が1以下なら
                        dp[left][right] = width;
                    }
                }

                for(int mid=left; mid<right; mid++){
                    dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid+1][right]);
                }
                
            }
        }

        cout << dp[0][n-1] << endl;
    }
    return 0;
}

/*以下備忘録

2n個の連続した組が削除できるならまずカウント
奇数個の余りなども含めて区間を二つに分け、それぞれの和を考える
これを並行して行う！！


*/