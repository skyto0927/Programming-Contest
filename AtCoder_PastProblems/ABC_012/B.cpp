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

    cout << setw(2) << setfill('0') << N/3600 << ":";
    N -= (N/3600)*3600;
    cout << setw(2) << setfill('0') << N/60 << ":";
    N -=  (N/60)*60;
    cout << setw(2) << setfill('0') << N << endl;
    return 0;
}