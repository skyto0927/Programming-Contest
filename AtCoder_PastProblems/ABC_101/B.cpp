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
    int SN = 0;
    while(n>0){
        SN += n%10;
        n /= 10;
    }

    if(N%SN == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}