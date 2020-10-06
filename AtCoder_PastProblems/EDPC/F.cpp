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
    string s,t; cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

    REP(i,s.size()){
        REP(j,t.size()){
            if(s[i]==t[j]){
                chmax(dp[i+1][j+1], dp[i][j]+1);
            }
            chmax(dp[i+1][j+1], dp[i][j+1]);
            chmax(dp[i+1][j+1], dp[i+1][j]);
        }
    }

    int i = s.size();
    int j = t.size();
    string ans;
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else{
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
    }
    reverse(ALL(ans));

    cout << ans << endl;
    return 0;
}