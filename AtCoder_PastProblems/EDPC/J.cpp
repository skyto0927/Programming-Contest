#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}

double dp[301][301][301];
int N;

double rec(int a, int b, int c){
    //cout << a << b << c << endl;

    if(dp[a][b][c] != -1){//計算済みなら
        return dp[a][b][c];
    }

    if(a==0 && b==0 && c==0){//最後の状況なら
        dp[0][0][0] = 0.0;
        return 0;
    }

    double res = 0.0;
    if(a) res += rec(a-1,b,c)*a;
    if(b) res += rec(a+1,b-1,c)*b;
    if(c) res += rec(a,b+1,c-1)*c;
    res += N;
    res *= 1.0/(a+b+c);
    return dp[a][b][c] = res;
}

int main() {
    cin >> N;
    vector<int> cnt(3,0);
    REP(i,N){
        int a; cin >> a;
        cnt[a-1] ++;
    }

    REP(i,301){
        REP(j,301){
            REP(k,301){
                dp[i][j][k] = -1.0;
            }
        }
    }
    cout << fixed << setprecision(10) << rec(cnt[0],cnt[1],cnt[2]) << endl;

return 0;
}