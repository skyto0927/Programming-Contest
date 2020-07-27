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

    vector<int> R(9,0);
    REP(i,N){
        int a; cin >> a;
        int r = a/400;
        if(r < 8) R[r]++;
        else R[8]++;
    }
    int cnt = 0;
    REP(i,8){
        if(R[i]>0) cnt++;
    }
    
    if(cnt==0 && R[8]>0){
        cout << 1 << " " << R[8] << endl;
    }else cout << cnt << " " << cnt+R[8] << endl;

    
    return 0;
}