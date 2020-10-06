#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MAX_P = 2e5;

int main() {
    int X; cin >> X;
    vector<int> primes(MAX_P,1);
    primes[0] = 0;
    primes[1] = 0;

    FOR(i,2, MAX_P){
        int itr = i;
        itr += i;
        while(itr <= MAX_P){
            primes[itr] = 0;
            itr += i;
        }
    }
    
    int ans = X;
    while(1){
        if(primes[ans] == 1){
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
    return 0;
}