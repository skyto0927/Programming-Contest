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
    int a,b; cin >> a >> b;
    vector<int> A(4,0);
    A[a] = 1;
    A[b] = 1;
    FOR(i,1,4){
        if(A[i]==0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}