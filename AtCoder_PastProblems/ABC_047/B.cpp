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
    int  W,H,N; cin >> W >> H >> N;

    int l=0,r=W,d=0,u=H;
    REP(i,N){
        int x,y,a; cin >> x >> y >> a;
        switch (a){
            case 1:
                l = max(l,x);
                break;
            
            case 2:
                r = min(r,x);
                break;
            
            case 3:
                d = max(d,y);
                break;
            
            case 4:
                u = min(u,y);
                break;
        }
    }
    if(l<r && d<u) cout << (r-l)*(u-d) << endl;
    else cout << 0 << endl;
        

    return 0;
}