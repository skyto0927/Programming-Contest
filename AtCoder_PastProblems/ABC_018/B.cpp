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
    int N; cin >> N;
    REP(i,N){
        int l,r; cin >> l >> r;
        l--;
        string left = s.substr(0,l);
        string mid = s.substr(l,r-l);
        string right = s.substr(r);
        reverse(ALL(mid));
        s = left + mid + right;
    }
    cout << s << endl;
    
    return 0;
}