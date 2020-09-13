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
    int N,K; cin >> N >> K;
    if((N-1)*(N-2)/2<K){
        cout << -1 << endl;
        return 0;
    }

    int cnt = (N-1)*(N-2)/2-K;

    cout << (N-1) + (N-1)*(N-2)/2 - K << endl;
    FOR(i,1,N){
        cout << 1 << " " << i+1 << endl;
    }

    bool ok = true;
    FOR(i,1,N-1){
        FOR(j,i+1,N){
            if(cnt<=0){
                ok = false;
                break;
            }
            cout << i+1 << " " << j+1 << endl;
            cnt--;
        }
        if(!ok) break;
    }
    

    return 0;
}