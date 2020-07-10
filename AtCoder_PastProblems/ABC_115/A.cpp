#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int D; cin >> D;
    switch (D)
    {
    case 25:
        cout << "Christmas" << endl;
        break;
    case 24:
        cout << "Christmas Eve" << endl;
        break;
    case 23:
        cout << "Christmas Eve Eve" << endl;
        break;
    case 22:
        cout << "Christmas Eve Eve Eve" << endl;
        break;
    }
    return 0;
}