#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,C,D; cin >> A >> B >> C >> D;
    if(A+B>C+D) cout << "Left" << endl;
    else if(A+B<C+D) cout << "Right" << endl;
    else cout << "Balanced" << endl;
    return 0;
}