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
    vector<pair<int,int>> A(N);
    REP(i,N){
        int a; cin >> a;
        A[i] = {a,i+1};
    }
    sort(ALL(A));
    REP(i,N){
        cout << A[i].second << " ";
    }
    cout << endl;
    return 0;
}