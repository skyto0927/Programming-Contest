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
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    REP(i,x2-x1) cout << 'R';
    REP(i,y2-y1) cout << 'U';
    REP(i,x2-x1) cout << 'L';
    REP(i,y2-y1) cout << 'D';

    cout << 'D';
    REP(i,x2-x1+1) cout << 'R'; 
    REP(i,y2-y1+1) cout << 'U';
    cout << 'L'; 
    cout << 'U'; 
    REP(i,x2-x1+1) cout << 'L';
    REP(i,y2-y1+1) cout << 'D';
    cout << 'R';
    cout << endl;
    return 0;
}