#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    ll X;
    cin >> X;

    vector<ll> Z(1000);
    REP(i,1000){
        Z[i] = pow(i,5);
    }

    REP(i,999){
        FOR(j,i+1,1000){
            if(Z[j]-Z[i] == X){
                cout << j << " " << i << endl;
                return 0;
            }
            if(Z[j]+Z[i] == X){
                cout << j << " " << -i << endl;
                return 0;
            }
        }
    }

    return 0;
}