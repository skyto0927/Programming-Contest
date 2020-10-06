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


int main() {
    int N; cin >> N;
    string S; cin >> S;
    S.push_back('.');
    int ans = 0;
    char cur = S[0];
    REP(i,S.size()){
        if(S[i] != cur){
            ans ++;
            cur = S[i];
        }
    }
    cout << ans << endl;
    return 0;
}