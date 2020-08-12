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
    int k; cin >> k;
    set<string> A;
    if(S.size() < k){
        cout << 0 << endl;
        return 0;
    }
    REP(i,S.size()-k+1){
        string s = S.substr(i,k);
        A.insert(s);
    }
    cout << A.size() << endl;
    return 0;
}