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
    vector<int> L(N);
    REP(i,N) cin >> L[i];
    sort(ALL(L));
    int sum = 0;
    REP(i,N-1) sum += L[i];
    if(sum <= L[N-1]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}