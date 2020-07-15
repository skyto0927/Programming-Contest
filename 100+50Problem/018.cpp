#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    REP(i,n) cin >> S[i];

    int q;
    cin >> q;
    vector<int> T(q);
    REP(i,q) cin >> T[i];

    int count = 0;
    REP(i, q){
        if(binary_search(ALL(S), T[i])) count ++;

    }
    cout << count << endl;
    return 0;
}
