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
    vector<vector<char>> S(4, vector<char>(4));
    REP(i,4){
        REP(j,4){
            cin >> S[i][j];
        }
    }
    REPR(i,3){
        REPR(j,3){
            cout << S[i][j];
            if(j!=0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}