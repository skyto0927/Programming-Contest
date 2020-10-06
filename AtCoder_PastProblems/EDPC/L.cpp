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

int N;
ll dp[4000][4000];//[l,r)
ll A[4000];

ll rec(int l, int r){
    if(dp[l][r] != LINF) return dp[l][r];

    if (l==r) return 0;

    int p = (N-r+l)%2;//偶数なら先手
    if(p==0) return dp[l][r] = max(rec(l+1,r)+A[l], rec(l,r-1)+A[r-1]);
    else return dp[l][r] = min(rec(l+1,r)-A[l], rec(l,r-1)-A[r-1]);
}

int main() {
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    
    REP(i,N){
        REP(j,N+1){
            dp[i][j] = LINF;
        }
    }

    cout << rec(0,N) << endl;
return 0;
}