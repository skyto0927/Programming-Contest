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
    string S; cin >> S;
    int T; cin >> T;
    int x = 0;
    int y = 0;
    int cnt = 0;
    REP(i,S.size()){
        switch (S[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'D':
            y--;
            break;
        case 'U':
            y++;
            break;
        case '?':
            cnt++;
            break;
        }
    }
    if(T==1) cout << abs(x) + abs(y) + cnt << endl;
    else{
        if(cnt < abs(x)+abs(y)){
            cout << abs(x) + abs(y) - cnt << endl;
        }else{
            if(cnt%2 == (abs(x)+abs(y))%2) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
    return 0;
}