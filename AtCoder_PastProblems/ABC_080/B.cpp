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
    int n = N;

    int f = 0;
    while(n>0){
        f += n%10;
        n /= 10;
    }
    cout << (N%f==0? "Yes": "No") << endl;
    return 0;
}