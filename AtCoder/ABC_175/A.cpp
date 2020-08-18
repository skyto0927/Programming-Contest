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
    string s; cin >> s;
    if(s[0]=='R'&&s[1]=='R'&&s[2]=='S') cout << 2 << endl;
    else if(s[0]=='S'&&s[1]=='R'&&s[2]=='R') cout << 2 << endl;
    else if(s[0]=='R'&&s[1]=='R'&&s[2]=='R') cout << 3 << endl;
    else if(s[0]=='R'&&s[1]=='S'&&s[2]=='R') cout << 1 << endl;
    else  cout << count(ALL(s),'R') << endl;
    return 0;
}