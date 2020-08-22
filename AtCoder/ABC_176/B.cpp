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
    string N; cin >> N;
    int sum = 0;
    REP(i,N.size()){
        sum += N[i]-'0';
        sum %= 9;
    }

    cout << (sum==0?"Yes":"No") << endl;

    return 0;
}