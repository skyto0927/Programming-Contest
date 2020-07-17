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
    vector<int> X_cnt(26,0);
    vector<int> Y_cnt(26,0);
    REP(i,N) X_cnt[S[i]-'a'] ++;

    int ans = 0;
    REP(i,N){
        X_cnt[S[i]-'a']--;
        Y_cnt[S[i]-'a']++;

        int cnt = 0;
        REP(j,26){
            if(X_cnt[j]>0 && Y_cnt[j]>0) cnt++;
        }
        ans = max(ans,cnt);

    }
    cout << ans << endl;

    return 0;
}