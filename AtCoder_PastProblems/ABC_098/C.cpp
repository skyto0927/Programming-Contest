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
    string S; cin >> S;
    vector<int> W_num(N,0), E_num(N,0);
    REP(i,N-1){
        if(S[i] == 'W') W_num[i+1] = W_num[i] + 1;
        else W_num[i+1] = W_num[i];
    }

    for(int i=N-1; i>0; i--){
        if(S[i] == 'E') E_num[i-1] = E_num[i] + 1;
        else E_num[i-1] = E_num[i];
    }

    int ans = INF;
    REP(i,N){
        ans = min(ans, W_num[i]+E_num[i]);
    }
    cout << ans << endl;

    return 0;
}