#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    ll all = 0;
    REP(i,N){
        cin >> A[i];
        all += A[i];
    }

    
    for(int j=1; j<N; j+=2){
        all -= 2*A[j%N];
    }
    cout << all <<" ";

    ll ans = all/2;

    REP(i,N-1){
        ans = A[i] - ans;
        cout << 2*ans << " ";
    }
    
    cout << endl;
   

    return 0;
}