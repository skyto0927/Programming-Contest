#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int X,A,B;  cin >> X >> A >> B;
    if(B-A<=0) cout << "delicious" << endl;
    else if(B-A <= X) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return 0;
}