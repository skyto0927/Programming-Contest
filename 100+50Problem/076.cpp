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
    vector<ll> A(N+1, 0);
    FOR(i,1,N+1){
        cin >> A[i];//A[i]... [0,i]の和
        A[i] += A[i-1];
    }

    FOR(k,1,N+1){
        ll ans = 0;
        FOR(i,0,N-k+1){
            ans = max(ans, A[i+k] - A[i]);//連続k個...[i,i+k)
        }//i,i+1,i+2,...,i+k-1で確かにk個
        cout << ans << endl;
    }

    return 0;
}