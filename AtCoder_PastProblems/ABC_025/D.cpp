#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<ll> dp(1<<25, 0);

int main() {
    vector<int> table(25,-1);//table[i] に入った数字の座標にとぶ
    REP(i,5){
        REP(j,5){
            int a; cin >> a;
            if(a!=0){
                table[a] = 5*i + j;
            }
        }
    }

    dp[0] = 1;


    return 0;
}