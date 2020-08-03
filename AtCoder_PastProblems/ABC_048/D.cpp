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
    int N = s.size();
    if(s[0] == s[N-1] && N%2==0) cout << "First" << endl;
    else if(s[0] == s[N-1] && N%2==1) cout << "Second" << endl;
    else if(s[0] != s[N-1] && N%2==0) cout << "Second" << endl;
    else if(s[0] != s[N-1] && N%2==1) cout << "First" << endl;
    return 0;
}