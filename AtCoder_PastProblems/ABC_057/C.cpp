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
    ll N; cin >> N;
    REPR(k,sqrt(N)){
        if(N%k == 0){
            int a = to_string(N/k).size();
            int b = to_string(k).size();
            cout << max(a,b) << endl;
            return 0; 
        }
    }
    return 0;
}