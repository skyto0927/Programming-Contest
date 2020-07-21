#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    vector<int> A(3); cin >> A[0] >> A[1] >> A[2];

    sort(ALL(A));

    int ans = 0;
    ans += (A[2]-A[0])/2;
    A[0] = A[0] + ((A[2]-A[0])/2)*2;

    ans += (A[2]-A[1])/2;
    A[1] = A[1] + ((A[2]-A[1])/2)*2;

    sort(ALL(A));

    if(A[0]==A[1] && A[1]==A[2]) cout << ans << endl;
    else if (A[0]==A[1] && A[1]!=A[2]) cout << ans+1 << endl;
    else cout << ans+2 << endl;

    return 0;
}