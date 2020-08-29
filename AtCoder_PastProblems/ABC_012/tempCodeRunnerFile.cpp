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
    int N; cin >> N;
    int sum = 0;
    FOR(i,1,10){
        FOR(j,1,10){
            sum += i*j;
        }
    }
    int n = sum - N;

    FOR(i,1,10){
        if(n%i==0){
            if(n%i<10) cout << i << " x " << n/i << endl;
        }
    }
    return 0;
}