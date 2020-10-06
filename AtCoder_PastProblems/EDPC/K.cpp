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

int main() {
    int N,K; cin >> N >> K;
    vector<int> A(N);
    vector<int> dp(K+1,0);
    REP(i,N){
        cin >> A[i];
    }

    REP(i,K){
        REP(j,N){
            if(i+A[j]>K) continue;

            if(dp[i]==0){
                dp[i+A[j]] ++;
            }
        }
    }

    cout << (dp[K]?"First":"Second") << endl;
    return 0;
}