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
    vector<int> A(N); REP(i,N) cin >> A[i];

    
    vector<int> d(N+1);
    d[0] = abs(A[0]);
    d[N] = abs(A[N-1]);
    FOR(i,1,N){
        d[i] = abs(A[i] - A[i-1]);
    }

    int sum = 0;
    REP(i,N+1){
        sum += d[i];
    }

    vector<int> dd(N);
    dd[0] = abs(A[1]);
    dd[N-1] = abs(A[N-2]);
    FOR(i,1,N-1){
        dd[i] = abs(A[i+1] - A[i-1]);
    }

    REP(i,N){
        cout << sum - d[i] - d[i+1] + dd[i] << endl;
    }


    return 0;
}