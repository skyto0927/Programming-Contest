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
    int N,L; cin >> N >> L;

    int sum = 0;
    REP(i,N){
        sum += L+i;
    }

    int R = L+N-1;

    if(L>0) cout << sum-L << endl;
    else if(L<=0 && 0<=R) cout << sum << endl;
    else cout << sum-R << endl;
    return 0;
}