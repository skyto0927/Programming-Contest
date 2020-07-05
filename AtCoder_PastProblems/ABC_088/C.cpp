#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    vector<vector<int>> c(3, vector<int>(3));
    REP(i,3){
        REP(j,3){
            cin >> c[i][j];
        }
    }
    if(c[0][0]-c[0][1]==c[1][0]-c[1][1] && c[0][0]-c[0][1]==c[2][0]-c[2][1]){
        if(c[0][1]-c[0][2]==c[1][1]-c[1][2] && c[0][1]-c[0][2]==c[2][1]-c[2][2]){
            if(c[0][0]-c[1][0]==c[0][1]-c[1][1] && c[0][0]-c[1][0]==c[0][2]-c[1][2]){
                if(c[1][0]-c[2][0]==c[1][1]-c[2][1] && c[1][0]-c[2][0]==c[1][2]-c[2][2]){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}