#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int H,W; cin >> H >> W;
    vector<vector<char>> P(H+2, vector<char>(W+2, '#'));
    REP(i,H){
        string s; cin >> s;
        REP(j,W){
            P[i+1][j+1] = s[j];
        }
    }
    REP(i,H+2){
        REP(j,W+2){
            cout << P[i][j];
        }
        cout << endl;
    }

    return 0;
}