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
    int N; cin >> N;
    string S; cin >> S;
    if (S.size()%2==1){
        cout << "No" << endl;
        return 0;
    }

    string l = S.substr(0,N/2);
    string r = S.substr(N/2,N/2);

    cout << (l==r?"Yes":"No") << endl;
    return 0;
}