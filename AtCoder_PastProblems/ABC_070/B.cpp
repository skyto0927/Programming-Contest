#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int A,B,C,D; cin >> A >> B >> C >> D;
    vector<int> num(110);
    num[A]++;
    num[B+1]--;
    num[C]++;
    num[D+1]--;
    int ans = 0;
    REP(i,100) num[i+1] += num[i];
    REP(i,101){
        if (num[i]==2) ans++;
    }

    cout << max(ans-1,0) << endl;
    
    return 0;
}