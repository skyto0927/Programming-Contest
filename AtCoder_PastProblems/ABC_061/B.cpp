#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,M; cin >> N >> M;
    vector<int> A(N,0);
    REP(i,M){
        int a,b; cin >> a >> b;
        A[a-1]++;
        A[b-1]++;
    }
    REP(i,N){
        cout << A[i] << endl;
    }
    return 0;
}