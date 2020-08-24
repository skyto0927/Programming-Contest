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
    int R,C,K; cin >> R >> C >> K;
    vector<vector<char>> G(R, vector<char>(C));
    REP(i,R){
        string s; cin >> s;
        REP(j,C) G[i][j] = s[j];
    }

    int ans = 0;
    FOR(i,K-1,R-K+1){
        int sum = 0;
        FOR(x,i-K+1,i+2*K-1){
            FOR(y,0,2*K-1){
                if(abs(x-i) + abs(y-K+1) <= K-1){
                    //cout << x << " " << y << endl;
                    if(G[x][y] == 'x') sum++;
                }
            }
        }

        if(sum==0) ans++;
        //cout<< i << " " << K-1 << ", " << sum << endl;

        FOR(j,K-1,C-K){
            REP(a,K){
                if(G[i-K+1+a][j-a] == 'x') sum--;
            }
            REP(a,K-1){
                if(G[i+K-1-a][j-a] == 'x') sum--;
            }
            //cout<< i << " " << j+1 << ", " << sum << endl;

            REP(a,K){
                if(G[i-K+1+a][j+1+a] == 'x') sum++;
            }
            REP(a,K-1){
                if(G[i+K-1-a][j+1+a] == 'x') sum++;
            }
            if(sum==0) ans++;
            //cout<< i << " " << j+1 << ", " << sum << endl;
        }
    }
    cout << ans << endl;
    return 0;
}