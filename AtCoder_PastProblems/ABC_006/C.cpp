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
    int N,M; cin >> N >> M;

    int a,b,c;
    if(M-2*N < 0){
        cout << "-1 -1 -1" << endl;
        return 0;
    }else{
        c = (M-2*N)/2;
        b = (M-2*N)%2;
        a = N-b-c;
        if(a<0){
            cout << "-1 -1 -1" << endl;
            return 0;
        }else{
            cout << a << " " << b << " " << c << endl;
        }
    }

    return 0;
}