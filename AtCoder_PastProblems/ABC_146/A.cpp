#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    string S; cin >> S;
    vector<string> day{"SUN","MON","TUE","WED","THU","FRI","SAT"};
    REP(i,7){
        if(S==day[i]){
            cout << 7-i << endl;
            return 0;
        }
    }
    return 0;
}