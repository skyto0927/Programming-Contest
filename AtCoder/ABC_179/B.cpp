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
    int cnt = 0;
    bool ok = false;
    REP(i,N){
        int a,b; cin >> a >> b;
        if(a==b){
            cnt++;
            if(cnt==3) ok = true;
        }else{
            cnt = 0;
        }
    }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}