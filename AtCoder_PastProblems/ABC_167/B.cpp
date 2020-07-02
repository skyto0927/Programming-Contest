#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,C,K; cin >>A>>B>>C>>K;
    if(K<=A){
        cout << K << endl;
    }else if(A<K && K<=A+B){
        cout << A << endl;
    }else if(A+B<K && K<=A+B+C){
        cout << 2*A-K+B << endl;
    }
    return 0;
}