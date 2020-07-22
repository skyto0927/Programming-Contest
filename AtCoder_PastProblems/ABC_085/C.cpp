#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N,Y; cin >> N >> Y;
    Y /= 1000;
    int x,y,z;
    int d = Y-N;

    if(d<0){
        cout << "-1 -1 -1" << endl;
        return 0;
    }else{
        int x = 0;
        int y,z;
        z = -1;
        while(9*x <= d){
            if((d-9*x)%4 == 0){
                y = (d-9*x)/4;
                z = N-x-y;
                if(z>=0) break;
            }
            x++;
        }
        if(z>=0) cout << x << " " << y << " " << z << endl;
        else cout << "-1 -1 -1" << endl;
    }
    return 0;
}