#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> A(N);
    REP(i,N) cin >> A[i];

    int n = N-1;
    while(n>=0){
        cout << A[n] << " ";
        n -= 2;
    }
    if(n== -2) n = 1;
    else n = 0;
    while(n<=N-1){
        cout << A[n] << " ";
        n += 2;
    }
    cout << endl;
    return 0;
}