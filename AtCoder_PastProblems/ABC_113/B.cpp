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
    double T,A; cin >> T >> A;

    double dist = INF;
    int itr = 0;
    REP(i,N){
        double h; cin >> h;
        if(dist > abs(T-h*0.006 - A)){
            dist = abs(T-h*0.006 - A);
            itr = i+1;
        }
    }

    cout << itr << endl;
    return 0;
}