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
    vector<int> X(N); 
    REP(i,N) cin >> X[i];

    vector<int> Y(X);
    sort(ALL(Y));
    int l = Y[N/2-1], r = Y[N/2];

    REP(i,N){
        if(X[i] >= r) cout << l << endl;
        else if(X[i] <= l) cout << r << endl;
    }

    return 0;
}