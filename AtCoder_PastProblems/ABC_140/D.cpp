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
    string S; cin >> S;
    int ans = 0;

    char s = S[0];
    int cnt = 1;
    int len = 0;
    REP(i,S.size()){
        if(S[i] != s){
            cnt++;
            ans += len-1;
            len = 1;
            s = S[i];
        }else{
            len ++;
        }
    }
    ans += len-1;

    cout << min(ans+2*K, N-1) << endl;
    return 0;
}