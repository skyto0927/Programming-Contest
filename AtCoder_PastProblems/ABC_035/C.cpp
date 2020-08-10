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
    int N,Q; cin >> N >> Q;
    vector<int> A(N+1,0);
    REP(i,Q){
        int l,r; cin >> l >> r;
        l--;
        A[l]++;
        A[r]--;
    }
    REP(i,N){
        A[i+1] += A[i];
    }
    REP(i,N){
        cout << (A[i]%2==0?0:1);
    }
    cout << endl;
    return 0;
}