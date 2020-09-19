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
    ll N; cin >> N;
    vector<string> S(N);
    REP(i,N){
        cin >> S[i];
        sort(ALL(S[i]));
    }
    sort(ALL(S));

    ll cnt = 0;
    ll ans = 0;
    string str = S[0];
    REP(i,N){
        if(str == S[i]){
            cnt++;
        }else{
            ans += cnt*(cnt-1)/2;
            str = S[i];
            cnt = 1;
        }
    }
    ans += cnt*(cnt-1)/2;
    cout << ans << endl;
    return 0;
}