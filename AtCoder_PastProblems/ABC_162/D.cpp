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
    int N; cin >> N;
    string s; cin >> s;
    string S;

    vector<vector<int>> color(N+1,vector<int>(3,0));
    REP(i,N){
        if(s[i]=='R'){
            S.push_back('0');
            color[i][0]++;
        }else if(s[i]=='G'){
            S.push_back('1');
            color[i][1]++;
        }else if(s[i]=='B'){
            color[i][2]++;
            S.push_back('2');
        }
    }

    REP(i,N-1){
        REP(j,3){
            color[i+1][j] += color[i][j];
        }
    }
    ll ans = 0;
    FOR(i,1,N-1){
        int c = S[i]-'0';
        ans += color[i-1][(c+1)%3]*(color[N-1][(c+2)%3]-color[i][(c+2)%3]);
        ans += color[i-1][(c+2)%3]*(color[N-1][(c+1)%3]-color[i][(c+1)%3]);
        FOR(j,1,min(i,N-1-i)+1){
            if(S[i]!=S[i-j] && S[i]!=S[i+j] && S[i-j]!=S[i+j]){
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}