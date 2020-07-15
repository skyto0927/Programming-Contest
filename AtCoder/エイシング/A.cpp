#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int L,R,d; cin >> L >> R >> d;
    int l=0;
    FOR(i,1,L){
        if(i%d==0)l++;
    }
    int r=0;
    FOR(i,1,R+1) if(i%d==0) r++;
    cout<< r - l << endl;
    return 0;
}