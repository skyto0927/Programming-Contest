#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    char X,Y; cin >> X >> Y;
    if(X<Y) cout << "<" << endl;
    else if(X>Y) cout << ">" << endl;
    else cout << "=" << endl;
    return 0;
}