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

    
    vector<vector<bool>> dp(X.size()+1, vector<bool>(17000, 0));
    int geta = 8500;
    dp[0][geta + x_pos] = true;
    REP(k,X.size()){
        REP(n,17000){
            if(n+X[k] < 17000 && dp[k][n]) dp[k+1][n+X[k]] = true;
            if(n-X[k] >= 0 && dp[k][n]) dp[k+1][n-X[k]] = true;
        }
    }

    vector<vector<bool>> dp2(Y.size()+1, vector<bool>(17000, 0));
    dp2[0][geta] = true;
    REP(k,Y.size()){
        REP(n,17000){
            if(n+Y[k] < 17000 && dp2[k][n]) dp2[k+1][n+Y[k]] = true;
            if(n-Y[k] >= 0 && dp2[k][n]) dp2[k+1][n-Y[k]] = true;
        }
    }


    if(dp[X.size()][geta+x] && dp2[Y.size()][geta+y]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}