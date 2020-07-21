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
    int t_before = 0;
    int x_before = 0;
    int y_before = 0;
    REP(i,N){
        int t,x,y; cin >> t >> x >> y;
        if((t-t_before)%2 == (100000+x+y-x_before-y_before)%2 && abs(x-x_before)+abs(y-y_before) <= t-t_before){

            t_before = t;
            x_before = x;
            y_before = y;
        }else{
            cout << "No" << endl;
            return 0;
        }

    }
    cout << "Yes" << endl;
    return 0;
}