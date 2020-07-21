#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,K; cin >> A >> B >> K;
    set<int> ans;

    REP(i,min(B-A+1,K)){
        ans.insert(A+i);
        ans.insert(B-i);
    }
    for(auto a: ans) cout << a << endl;

    return 0;
}