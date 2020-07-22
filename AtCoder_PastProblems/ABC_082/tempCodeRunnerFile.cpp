#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    string s; cin >> s;
    int x,y; cin >> x >> y;

    vector<int> move;
    int cnt = 0;
    REP(i,s.size()){
        if(s[i] == 'F'){
            cnt++;
        }else{
            move.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt!=0) move.push_back(cnt);

    vector<int> X,Y;

    int x_pos = 0;

    REP(i,move.size()){
        if(i==0) x_pos = move[i];
        else if(i%2==0) X.push_back(move[i]);
        else Y.push_back(move[i]);
    }

    
    vector<vector<int>> dp(X.size()+1, vector<int>(20000, 0));
    int geta = 10000;
    dp[0][geta + x_pos] = 1;
    REP(k,X.size()){
        REP(n,20000){
            if(geta+n+X[k] < 20000) dp[k+1][geta+n+X[k]] += dp[k][geta+n];
            if(geta+n-X[k] >= 0) dp[k+1][geta+n-X[k]] += dp[k][geta+n];
        }
    }

    vector<vector<int>> dp2(Y.size()+1, vector<int>(20000, 0));
    dp2[0][geta] = 1;
    REP(k,Y.size()){
        REP(n,20000){
            if(geta+n+Y[k] < 20000) dp2[k+1][geta+n+Y[k]] += dp2[k][geta+n];
            if(geta+n-Y[k] >= 0) dp2[k+1][geta+n-Y[k]] += dp2[k][geta+n];
        }
    }


    if(dp[X.size()][geta+x]>0 && dp2[Y.size()][geta+y]>0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}