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
    int N; cin >> N;
    vector<string> X;
    REP(i,5){
        REP(j,5){
            X.push_back(S.substr(i,1) + S.substr(j,1));
        }
    }
    sort(ALL(X));
    cout << X[N-1] << endl;
    return 0;
}