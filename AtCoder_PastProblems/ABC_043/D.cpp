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
    if(s.size()==2){
        if(s[0] == s[1]) cout << "1 2" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }
    REP(i,s.size()-2){
        if(s[i] == s[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }else if(s[i] == s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}